# ❌⭕ Tic-Tac-Toe - C++ Console Game

## 📢 Author's Note
> **Topic:** Arrays, Pointers & Game Logic
>
> - 🌏 **I'm not good at English!**
> - 🤖 Gemini only helped me complete the comments and translation.
> - 👨‍💻 **All code is mine, no copy.**
> - ⏱️ This topic took me **15 minutes**.

## 📝 About The Project
This is a simple implementation of the classic **Tic-Tac-Toe** game written in C++.
The player competes against a Computer opponent (which makes random moves) on a standard 3x3 grid. The first to align 3 symbols horizontally, vertically, or diagonally wins.

## 🚀 Features
1.  **Player vs Computer:** Play against an AI that moves randomly.
2.  **Input Validation:**
    - Prevents users from entering non-integer characters.
    - Prevents users from selecting an already occupied spot.
3.  **Win/Tie Detection:**
    - Automatically checks for a winner or a draw after every move.
4.  **Clean UI:** Redraws the board after every turn for a smooth experience.

## 🛠️ Technical Details
- **Data Structure:** Uses a 1D array (`char space[9]`) to represent the 3x3 grid.
- **Pointers:** passes the board array to functions using pointers (`char *space`).
- **Randomization:** Uses `srand(time(0))` to ensure the computer's moves are different each game.

## 📸 Example Usage
```text
   |   |   
---|---|---
   |   |   
---|---|---
   |   |   

Enter your move (0-8): 0
 X |   |   
---|---|---
   | O |   
...
Player wins!
