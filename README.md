📘 **HANGMAN GAME (C Programming)**

📄 **ABSTRACT**  
The Hangman Game is a terminal-based word guessing application written in C that lets users play the classic Hangman game interactively. The system chooses a random word from a built-in list or allows a user-entered secret word, then provides hints and tracks guesses. Players reveal the word one letter at a time and must complete the word before 6 incorrect attempts.  
This project demonstrates key C programming concepts such as structures, arrays, strings, loops, conditionals, and modular function-based programming, making it ideal for beginners and students.

---

✨ **FEATURES**

**Core Functionalities**  
🎯 Two game modes: Built-in list or user-entered secret word  
💡 Hint display for every secret word  
⬜ Dynamic word reveal using underscore placeholders  
🖼️ Progressive ASCII Hangman drawing for each wrong attempt  
🔁 Prevents duplicate guesses (case-insensitive)  
🔤 Accepts single letter or full word guess  
✅ Win condition when the word is correctly revealed  
❌ Lose condition when max tries are reached  
🖥️ Fully terminal-based gameplay  

📌 **FUNCTIONAL REQUIREMENTS**

**User Interaction**  
- Runs entirely on terminal (CLI)  
- Takes alphabet or full-word input  
- Validates input before processing  

**Game Controls**  

➕ **Guess a Letter**  
Reveal parts of the word by entering one character.

📋 **View Progress**  
Game continuously prints revealed word state and guessed letters.

🖼️ **Wrong Guess Update**  
Hangman drawing updates stage-by-stage for errors.

🎉 **Win Feedback**  
Success message displayed when the word is completed.

😔 **Lose Feedback**  
Failure message shown when tries are exhausted.

**Game Flow**  
- Game loops until `Win` or `Lose` is triggered  
- Handles punctuation and capitalization safely  
- Ensures smooth gameplay transitions  


---

3️⃣ **DATA SOURCE**

- Words and hints are stored internally in a structured list  
- No external data files required  
- Random selection happens every game session  

---

📸 **SCREENSHOTS**

**Start Game + Mode Selection**  
<img width="644" height="130" alt="image" src="https://github.com/user-attachments/assets/1e431292-0b04-4f53-9f97-ccb69624f099" />


**Correct Letter Guess Feedback**  
<img width="633" height="447" alt="image" src="https://github.com/user-attachments/assets/5563b527-5f6f-48af-bd97-d2b9f40a29c9" />



**Wrong Letter Guess & Hangman Stage Draw**  
<img width="606" height="485" alt="image" src="https://github.com/user-attachments/assets/6f93be22-a45d-413c-908f-ec807a4a9b10" />


**Duplicate Guess Warning**  
<img width="584" height="448" alt="image" src="https://github.com/user-attachments/assets/1f339d3c-810e-4e1c-859a-cd0cbc619e27" />


**Win Message Output**  
<img width="688" height="499" alt="image" src="https://github.com/user-attachments/assets/c937fd57-887b-4a1e-892d-a247c6348e20" />


**Lose Message Output**  
<img width="671" height="421" alt="image" src="https://github.com/user-attachments/assets/e0c2380c-13bf-437a-b741-9c0498c5073b" />


---

**THANK YOU!**
**AMRITA K**





