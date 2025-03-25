#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

void historyGame()
{
    int n;
    int score = 0;

    cout << "Welcome to the Political Game." << endl;
    cout << "1. Who is the father of Capitalism" << endl;
    cout << "1) Adam Smith" << endl;
    cout << "2) John Adams" << endl;
    cin >> n;
    if (n == 1)
    {
        score += 20;
    }
    
    cout << "2. Who is the father of Communism" << endl;
    cout << "1) Vladimir Lenin" << endl;
    cout << "2) Karl Marx" << endl;
    cin >> n;
    if (n == 2)
    {
        score += 20;
    }

    cout << "3. What happened in tiananmen square 1989" << endl;
    cout << "1) Nothing" << endl;
    cout << "2) Protests that lead to a massacre" << endl;
    cin >> n;
    if (n == 2)
    {
        score += 20;
    }
    

    cout << "4. What was the 2024 presidential vote in terms of electoral college" << endl;
    cout << "1) Harris: 226 / Trump: 312" << endl;
    cout << "2) Harris: 240 / Trump: 298" << endl;
    cin >> n;
    if (n == 1)
    {
        score += 20;
    }

    cout << "5. Do you think Ted Kaczynski was right" << endl;
    cout << "1) Yes" << endl;
    cout << "2) No" << endl;
    cin >> n;
    if (n == 1)
    {
        score += 20;
    }
    
    
    cout << "You Scored " << score << "/100" << endl;
    if (score == 100)
    {
        cout << "You are Champion" << endl;
    }
    else if (score == 80)
    {
        cout << "You did Good" << endl;
    }
    else if (score == 60)
    {
        cout << "You did OK" << endl;
    }
    else if (score == 40)
    {
        cout << "You can do better" << endl;
    }
    else if (score == 20)
    {
        cout << "Please read a book" << endl;
    }
    else if (score == 0)
    {
        cout << "Do you live under a rock?" << endl;
    }
}

void output(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i];
    }
    cout << endl;
}

void mastermind() {
    cout << "Welcome to Mastermind!!" << endl;
    cout << "You are given a maximum of 10 tries. Choose wisely!!" << endl;

    const int length = 5;  // Length of the secret code
    const int attempts = 10;  // Max number of attempts
    int iterations = 0;
    int score = 0;

    srand((unsigned) time(NULL));
    int random[length];  // The secret code
    bool guessed[length] = {false};  // Track correctly guessed positions

    vector<int> usedNumbers;  // Track used numbers to ensure uniqueness

    // Generate unique random numbers
    for (int i = 0; i < length; i++) {
        int num;
        do {
            num = 1 + (rand() % 9);  // Generate a number between 1 and 9
        } while (find(usedNumbers.begin(), usedNumbers.end(), num) != usedNumbers.end());  
        usedNumbers.push_back(num);  // Store the unique number
        random[i] = num;  // Assign to sequence
    }

    int inputs[length];

    while (iterations < attempts) {
        cout << "\nAttempt " << iterations + 1 << " of " << attempts << ". Current Score: " << score << endl;
        cout << "Enter " << length << " numbers (1-9) with NO duplicates: ";

        // Take input and validate
        vector<int> userNumbers;  // Track user's inputs to prevent duplicates
        for (int i = 0; i < length; i++) {
            cin >> inputs[i];

            // Ensure the number is within range
            while (inputs[i] < 1 || inputs[i] > 9 || find(userNumbers.begin(), userNumbers.end(), inputs[i]) != userNumbers.end()) {
                cout << "Invalid input. Enter a UNIQUE number between 1 and 9: ";
                cin >> inputs[i];
            }
            userNumbers.push_back(inputs[i]);  // Store unique input
        }

        // Create arrays to track matches
        bool matched[length] = {false};  // Track which numbers were matched
        bool found[length] = {false};  // Track correct guesses
        bool misplaced[length] = {false};  // Track misplaced guesses

        // First pass: Check for exact matches
        for (int i = 0; i < length; i++) {
            if (inputs[i] == random[i]) {
                found[i] = true;
                matched[i] = true;  // Mark as matched
                score++;
            }
        }

        // Second pass: Check for misplaced numbers
        for (int i = 0; i < length; i++) {
            if (!found[i]) {  // Only check misplaced if it's not already correct
                for (int j = 0; j < length; j++) {
                    if (inputs[i] == random[j] && i != j && !matched[j]) {
                        misplaced[i] = true;
                        matched[j] = true;  // Prevent duplicate misplaced hints
                        break;
                    }
                }
            }
        }

        // Display feedback for each index
        cout << "Feedback: ";
        for (int i = 0; i < length; i++) {
            if (found[i]) {
                cout << "[Correct: " << inputs[i] << "] ";
            } else if (misplaced[i]) {
                cout << "[Misplaced: " << inputs[i] << "] ";
            } else {
                cout << "[Wrong: " << inputs[i] << "] ";
            }
        }
        cout << endl;

        iterations++;

        // Check if the player has won
        bool done = true;
        for (int i = 0; i < length; i++) {
            if (!found[i]) {
                done = false;
                break;
            }
        }

        if (done) {
            cout << "Congratulations! You've guessed the correct sequence!\n";
            return;
        }
    }

    // If max attempts are reached
    cout << "\nGame over! You've used all attempts.\n";
    cout << "The correct sequence was: ";
    for (int i = 0; i < length; i++) {
        cout << random[i] << " ";
    }
    cout << endl;
}

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentMarker;
int currentPlayer;

void drawBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " \n";
    cout << "\n";
}

bool checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') return false;
        }
    }
    return true;
}

void playTurn() {
    int choice;
    cout << "Player " << currentPlayer << " (" << currentMarker << "), enter your move (1-9): ";
    cin >> choice;

    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
        cout << "Invalid move! Try again.\n";
        playTurn();
    } else {
        board[row][col] = currentMarker;
        if (checkWin()) {
            drawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            return;
        }
        if (checkDraw()) {
            drawBoard();
            cout << "It's a draw!\n";
            return;
        }
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
        currentMarker = (currentMarker == 'X') ? 'O' : 'X';
        drawBoard();
        playTurn();
    }
}

void ticTacToe() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    cout << "Player 1, choose your marker (X or O): ";
    cin >> currentMarker;
    currentPlayer = 1;
    if (currentMarker == 'X') {
        currentMarker = 'X';
    } else {
        currentMarker = 'O';
    }

    drawBoard();
    playTurn();
}

void games()
{
    int gameOption;
    do
    {
        cout << "Choose a Game:\n1. History Game\n2. Master Mind\n3. Tic-Tac-Toe\n4. Exit" << endl;
        cin >> gameOption;
        switch (gameOption)
        {
            case 1: historyGame(); break;
            case 2: mastermind(); break;
            case 3: ticTacToe(); break;
            case 4: cout << "Exiting Program"; break;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } 
    while (gameOption != 4);
    
}