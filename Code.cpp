/*
 * Project: Tic-Tac-Toe Console Game
 * Author: Rangerr
 * Description: A simple C++ game using arrays and pointers.
 */

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function Prototypes
void drawBoard(char *space);
void playerMove(char *space, char player);
void computerMove(char *space, char computer);
bool ifWin(char *space, char player, char computer);
bool ifTie(char *space);

int main() {
    // Seed the random number generator
    srand(time(0));

    // Initialize the board with empty spaces
    char space[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';

    drawBoard(space);

    // Main Game Loop
    while (true)
    {
        // 1. Player's Turn
        playerMove(space, player);
        if(ifWin(space, player, computer) || ifTie(space)){
            drawBoard(space); // Show final board state
            break;
        }

        // 2. Computer's Turn
        computerMove(space, computer);
        if(ifWin(space, player, computer) || ifTie(space)){
            drawBoard(space); // Show final board state
            break;
        }

        // 3. Update Board
        drawBoard(space);
    }
    return 0;
}

// Function to visualize the 3x3 grid
void drawBoard(char *space){
    cout << " " << space[0] << " | " << space[1] << " | " << space[2] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << space[3] << " | " << space[4] << " | " << space[5] << " " << endl;
    cout << "---|---|---" << endl;
    cout << " " << space[6] << " | " << space[7] << " | " << space[8] << " " << endl;
}

// Function to handle player input
void playerMove(char *space, char player){
    int move;
    do
    {
        cout << "Enter your move (0-8): ";
        cin >> move;

        // Input Validation: Check if input is NOT a number
        if (cin.fail())
        {
            cin.clear(); // Clear error flag
            cin.ignore(1000,'\n'); // Discard invalid input
            move = -1; // Force loop to repeat
            cout << "Invalid input" << endl;
            continue;
        }
        
        // Check if the spot is already taken
        if(space[move] != ' '){
            cout << "Someone has already marked this location" << endl;
        }
    } while (move > 8 || move < 0 || space[move] != ' ');
    
    // Mark the spot
    space[move] = player;
}

// Function to handle random computer moves
void computerMove(char *space, char computer){
    int move;
    do
    {
        move = rand() % 9; // Generate random number 0-8
    } while (space[move] != ' '); // Keep trying until an empty spot is found
    
    space[move] = computer;
}

// Function to check winning conditions
bool ifWin(char *space, char player, char computer){
    
    // Check Rows, Columns, and Diagonals
    // 0 1 2 (Row 1)
    if(space[0] != ' ' && space[0] == space[1] && space[1] == space[2] ){
        space[0] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    // 3 4 5 (Row 2)
    else if (space[3] != ' ' && space[3] == space[4] && space[4] == space[5]){
        space[3] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    // 6 7 8 (Row 3)
    else if (space[6] != ' ' && space[6] == space[7] && space[7] == space[8]){
        space[6] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    // 0 3 6 (Col 1)
    else if (space[0] != ' ' && space[0] == space[3] && space[3] == space[6]){
        space[0] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    // 1 4 7 (Col 2)
    else if (space[1] != ' ' && space[1] == space[4] && space[4] == space[7]){
        space[1] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    // 2 5 8 (Col 3)
    else if (space[2] != ' ' && space[2] == space[5] && space[5] == space[8]){
        space[2] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    // 0 4 8 (Diagonal 1)
    else if (space[0] != ' ' && space[0] == space[4] && space[4] == space[8]){
        space[0] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    // 2 4 6 (Diagonal 2)
    else if (space[2] != ' ' && space[2] == space[4] && space[4] == space[6]){
        space[2] == player ? cout << "Player wins!" << endl : cout << "Computer wins!" << endl; return 1;
    }
    return 0; // No winner yet
}

// Function to check for a Tie (Draw)
bool ifTie(char *space){
    for(int i = 0; i < 9; i++){
        if(space[i] == ' '){
            return 0; // If there is an empty space, game continues
        }
    }
    cout << "Tie!" << endl;
    return 1; // Board is full, it's a tie
}