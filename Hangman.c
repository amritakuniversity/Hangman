#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_WORD_LEN 100
#define MAX_TRIES 6
#define WORDLIST_SIZE 10

/* Simple tolower replacement (no <ctype.h>) */
char my_tolower(char c) {
    if (c >= 'A' && c <= 'Z') return (char)(c + ('a' - 'A'));
    return c;
}

/* Print current hangman state (simple ASCII stages) */
void print_hangman(int wrong) {
    const char *stages[] = {
        "  +---+\n  |   |\n      |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========\n",
        "  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n=========\n"
    };
    if (wrong < 0) wrong = 0;
    if (wrong > MAX_TRIES) wrong = MAX_TRIES;
    printf("%s", stages[wrong]);
}

/* Check if letter already guessed */
bool already_guessed(const char guessed[], int gcount, char ch) {
    for (int i = 0; i < gcount; ++i) {
        if (guessed[i] == ch) return true;
    }
    return false;
}

/* Update the revealed array and return number of newly revealed letters */
int reveal_letters(const char secret[], char revealed[], char guess) {
    int newly = 0;
    int n = strlen(secret);
    char lowg = my_tolower(guess);
    for (int i = 0; i < n; ++i) {
        if (my_tolower(secret[i]) == lowg && revealed[i] == '_') {
            revealed[i] = secret[i]; /* preserve original case */
            ++newly;
        }
    }
    return newly;
}

int main(void) {
    char secret[MAX_WORD_LEN] = {0};
    char revealed[MAX_WORD_LEN] = {0};
    char guessed[256]; /* store guessed characters */
    int guessed_count = 0;
    int wrong = 0;
    int choice = 0;

    const char *wordlist[WORDLIST_SIZE] = {
        "Programming", "elephant", "hangman", "computer", "university",
        "challenge", "pyramid", "butterfly", "island", "keyboard"
    };

    printf("Hangman (no <time.h>, no <ctype.h>)\n");
    printf("1) Pick from built-in word list (choose an index)\n");
    printf("2) Enter a secret word for player 2 to guess\n");
    printf("Choose mode (1 or 2): ");
    if (scanf("%d", &choice) != 1) {
        printf("Invalid input. Exiting.\n");
        return 1;
    }
    getchar(); /* consume newline */

    if (choice == 1) {
        int idx = 0;
        printf("\nWord list size = %d. Enter an index 1..%d: ", WORDLIST_SIZE, WORDLIST_SIZE);
        if (scanf("%d", &idx) != 1 || idx < 1 || idx > WORDLIST_SIZE) {
            printf("Invalid index. Exiting.\n");
            return 1;
        }
        /* copy from wordlist (index-1) */
        strncpy(secret, wordlist[idx - 1], MAX_WORD_LEN - 1);
        secret[MAX_WORD_LEN - 1] = '\0';
        getchar(); /* consume newline */
    } else {
        /* Get secret word from player 1 */
        printf("\nEnter the secret word (no spaces). Player 2 look away!\n> ");
        if (scanf("%99s", secret) != 1) {
            printf("Failed to read word. Exiting.\n");
            return 1;
        }
        /* attempt to hide previous input by printing newlines */
        for (int i = 0; i < 50; ++i) putchar('\n');
    }

    int len = (int)strlen(secret);
    if (len <= 0) {
        printf("Empty secret. Exiting.\n");
        return 1;
    }

    /* initialize revealed */
    for (int i = 0; i < len; ++i) {
        if (secret[i] == ' ' || secret[i] == '-' || secret[i] == '\'') {
            revealed[i] = secret[i]; /* keep punctuation/space visible */
        } else {
            revealed[i] = '_';
        }
    }
    revealed[len] = '\0';

    printf("Game start! You have %d wrong guesses allowed.\n\n", MAX_TRIES);
    while (wrong < MAX_TRIES) {
        /* display hangman and revealed word */
        print_hangman(wrong);
        printf("Word: ");
        for (int i = 0; i < len; ++i) printf("%c ", revealed[i]);
        printf("\n");

        /* show guessed letters */
        if (guessed_count > 0) {
            printf("Guessed: ");
            for (int i = 0; i < guessed_count; ++i) printf("%c ", guessed[i]);
            printf("\n");
        }

        /* prompt */
        char buf[64];
        printf("Enter a letter or guess the whole word: ");
        if (!fgets(buf, sizeof(buf), stdin)) {
            printf("Input error. Exiting.\n");
            return 1;
        }
        /* strip newline */
        size_t blen = strlen(buf);
        if (blen > 0 && buf[blen - 1] == '\n') buf[blen - 1] = '\0';

        if (strlen(buf) == 0) {
            printf("No input — try again.\n\n");
            continue;
        }

        if (strlen(buf) > 1) {
            /* Player attempted to guess the whole word */
            if (strcmp(buf, secret) == 0) {
                printf("\nCorrect! The word was \"%s\". You win!\n", secret);
                return 0;
            } else {
                ++wrong;
                printf("Wrong guess for the whole word. Wrong count: %d/%d\n\n", wrong, MAX_TRIES);
                continue;
            }
        }

        char guess = buf[0];

        /* already guessed? (case-insensitive) */
        char lowg = my_tolower(guess);
        if (already_guessed(guessed, guessed_count, lowg)) {
            printf("You already guessed '%c'. Try another.\n\n", guess);
            continue;
        }

        /* store guessed (lowercase) */
        guessed[guessed_count++] = lowg;

        /* check if letter present */
        int found = reveal_letters(secret, revealed, guess);
        if (found > 0) {
            printf("Good! Letter '%c' appears %d time(s).\n\n", guess, found);
        } else {
            ++wrong;
            printf("No '%c' in the word. Wrong: %d/%d\n\n", guess, wrong, MAX_TRIES);
        }

        /* check win */
        bool won = true;
        for (int i = 0; i < len; ++i) {
            if (revealed[i] == '_') { won = false; break; }
        }
        if (won) {
            print_hangman(wrong);
            printf("Word: ");
            for (int i = 0; i < len; ++i) printf("%c ", revealed[i]);
            printf("\n\nCongratulations — you revealed the word \"%s\"!\n", secret);
            return 0;
        }
    }

    /* lost */
    print_hangman(MAX_TRIES);
    printf("\nYou've been hanged. The correct word was: %s\n", secret);
    return 0;
}