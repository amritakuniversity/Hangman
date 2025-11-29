# Hangman
📘 **HANGMAN GAME (C Programming)**

📄 **ABSTRACT**  
The Hangman Game is a terminal-based word guessing application written in C that allows users to play the classic Hangman game interactively. The system selects a random word from a preset list and displays a helpful hint. The player must guess one letter at a time before the hangman drawing is completed. The player wins if the word is fully revealed within 6 incorrect attempts.  
This project demonstrates key C programming concepts such as structures, arrays, strings, file-less game logic, loops, conditional statements, and modular programming, making it ideal for beginners and students.

---

✨ **FEATURES**

**Core Functionalities**  
🎯 Random word selection from predefined list  
💡 Hint display for each word  
⬜ Dynamic word reveal using underscore placeholders  
🖼️ Progressive ASCII Hangman drawing for wrong guesses  
🔁 Prevention of repeated letter guesses  
✅ Win condition when full word is guessed  
❌ Lose condition when maximum tries are exceeded  
🖥️ Fully terminal-based, menu-free gameplay  
👨‍💻 Beginner-friendly implementation using functions and structures  

---

🛠️ **TECHNICAL REQUIREMENTS**

**System Requirements**
- Operating System: Windows / Linux / macOS  
- Terminal or Command Prompt  
- Minimum `4 MB RAM`  
- Minimal disk space  

**Software Requirements**
- C Compiler: `GCC / MinGW / Clang / MSVC`  
- Any code editor or IDE (`VS Code`, Code::Blocks, Dev-C++, etc.)  

**Programming Requirements**
- Programming Language: `C`  
- Supported Standards: `C89 / C99 / C11`  
- Required Header Files: `stdio.h`, `stdlib.h`, `string.h`, `stdbool.h`, `time.h`

---

📌 **FUNCTIONAL REQUIREMENTS**

**Gameplay Interface**
- Runs entirely through the terminal (CLI)  
- Displays word progress and hangman drawing  
- Accepts single-letter input from user  
- Validates guesses  

**Game Actions**

➕ **Guess a Letter**  
Enter one alphabet character to reveal parts of the word.

📋 **View Word Progress**  
The system shows guessed letters and unrevealed blanks.

🖼️ **Incorrect Try Hangman Update**  
The ASCII hangman art prints progressively for every wrong attempt.

🎉 **Victory Message**  
Shown when the word is guessed before the hangman completes.

😔 **Defeat Message**  
Displayed when 6 incorrect attempts are reached.

**Program Flow**
- Game continues in loop until `Win` or `Lose` condition is triggered  
- Prevents duplicate guesses  
- Handles invalid letter input  

---


---

 **DATA SOURCE**

- Words are stored internally using a structure with hints  
- No external files are required  
- Randomization occurs every program run  

---

📸 **SCREENSHOTS**

**Start Game + Hint**  
<img width="328" height="117" alt="image" src="https://github.com/user-attachments/assets/0ecb586a-cee3-4d0b-9b0b-cb3158f2afba" />


**Correct Letter Guess**  
<img width="357" height="522" alt="image" src="https://github.com/user-attachments/assets/878f6e87-8199-4c67-81e9-442fda06e4e4" />


**Wrong Letter Guess + Hangman Draw**  
<img width="662" height="488" alt="image" src="https://github.com/user-attachments/assets/df9d814a-0403-4214-86bf-d1ae7cae9144" />
<img width="665" height="644" alt="image" src="https://github.com/user-attachments/assets/9c443388-0f15-4de2-ba63-3a2cd45bb2e5" />
<img width="664" height="869" alt="image" src="https://github.com/user-attachments/assets/eae1e7d0-7973-4f01-9ccd-b774d42f7ab7" />

**Win Message**  
<img width="806" height="62" alt="image" src="https://github.com/user-attachments/assets/f6c2a63c-0624-4ec4-ba6c-8b1850d1c02b" />

**Lose Message**  
<img width="759" height="54" alt="image" src="https://github.com/user-attachments/assets/e813a199-f676-4cc4-90ad-ead15281d33b" />


---

📝 **AUTHOR**  
**AMRITA K**

