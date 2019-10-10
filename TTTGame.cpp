/* Class: TicTacToe
 * Author: Zexuan Huang
 * Description: A program that implements the game Tic-Tac-Toe
 */

#include <iostream>
#include "TicTacToe.h"
#include <ctime>
using namespace std;

int main() {

    TicTacToe Game;
    int playerNum;
    int inputRow, inputCol;
    char playAgain = 'y';

    cout << "Press \"y\" to continue." << endl;
    cin >> playAgain;

    while (playAgain == 'y') {
        cout << "Please enter the number of player(s): ";
        cin >> playerNum;

        if (playerNum == 1) { // User will be using 1 as Player Number

            cout << endl << "Game start, please proceed." << endl;
            Game.initializeBoard();

            while (!Game.checkForWin() && !Game.isBoardFull()) { // Loop for single player game
                Game.printBoard();
                cout << "What's your next move?" << endl;
                cout << "Row:";
                cin >> inputRow;
                cout << "Column:";
                cin >> inputCol;

                while((inputRow > 3)||(inputRow < 1)||(inputCol > 3)||(inputCol < 1)){ // If inputs are out of range
                    cout << "INPUT OUT OF RANGE, please enter your next move again" << endl;
                    cout << "What's your next move?" << endl;
                    cout << "Row:";
                    cin >> inputRow;
                    cout << "Column:";
                    cin >> inputCol;
                }
                while(!Game.placeMark(inputRow - 1, inputCol - 1)){ // If the grid is already occupied
                    cout << "CHOSEN GRID OCCUPIED, please enter your next move again" << endl;
                    cout << "What's your next move?" << endl;
                    cout << "Row:";
                    cin >> inputRow;
                    cout << "Column:";
                    cin >> inputCol;
                }
                Game.placeMark(inputRow - 1, inputCol - 1); // -1 to fit the index
                Game.changePlayer();

                if (Game.checkForWin()) { // If user wins
                    cout << "You win!" << endl;
                    cout << "Play again? (y/n)" << endl;
                    cin >> playAgain;
                    Game.changePlayer(); // Let user always be player 1
                }
                else if(Game.isBoardFull()){ // Board is full without a winner
                    cout << "Draw." << endl;
                    cout << "Play again? (y/n)" << endl;
                    cin >> playAgain;
                }
                else if (Game.getCurrentPlayerNumber() == 2) { // Computer acts by random number
                    srand(time(0));
                    while(!Game.placeMark(inputRow - 1, inputCol - 1)){
                        inputRow = (rand() % 3);
                        inputCol = (rand() % 3);
                    }
                    Game.changePlayer();
                    if (Game.checkForWin()) { // If computer wins
                        cout << "Computer WINS!!!" << endl;
                        cout << "Play again? (y/n)" << endl;
                        cin >> playAgain;
                    }
                }
            }
        }

        if (playerNum == 2) { // Loop for two-player game

            cout << endl << "Game start, Player 1, please proceed." << endl;
            Game.initializeBoard();

            while (!Game.checkForWin() && !Game.isBoardFull()) {
                Game.printBoard();
                cout << "Player 1, what's your next move?" << endl;
                cout << "Row:";
                cin >> inputRow;
                cout << "Column:";
                cin >> inputCol;

                while((inputRow > 3)||(inputRow < 1)||(inputCol > 3)||(inputCol < 1)){ // If inputs are out of range
                    cout << "INPUT OUT OF RANGE, please enter your next move again" << endl;
                    cout << "What's your next move?" << endl;
                    cout << "Row:";
                    cin >> inputRow;
                    cout << "Column:";
                    cin >> inputCol;
                }
                while(!Game.placeMark(inputRow - 1, inputCol - 1)){ // If the grid is already occupied
                    cout << "CHOSEN GRID OCCUPIED, please enter your next move again" << endl;
                    cout << "What's your next move?" << endl;
                    cout << "Row:";
                    cin >> inputRow;
                    cout << "Column:";
                    cin >> inputCol;
                }
                Game.placeMark(inputRow - 1, inputCol - 1); // -1 to fit the index
                Game.changePlayer();
                Game.printBoard();

                if (Game.checkForWin()) { // If Player 1 wins
                    cout << "Player 1 wins!" << endl;
                    cout << "Play again? (y/n)" << endl;
                    cin >> playAgain;
                    Game.changePlayer(); // Let the first player be player 1
                }
                else if(Game.isBoardFull()){ // Board is full without a winner
                    cout << "Draw." << endl;
                    cout << "Play again? (y/n)" << endl;
                    cin >> playAgain;
                }
                else if(Game.getCurrentPlayerNumber() == 2){ // Turn of player 2
                    cout << "Player 2, take your turn!" << endl;
                    cout << "Row:";
                    cin >> inputRow;
                    cout << "Column:";
                    cin >> inputCol;

                    while((inputRow > 3)||(inputRow < 1)||(inputCol > 3)||(inputCol < 1)){ // If inputs are out of range
                        cout << "INPUT OUT OF RANGE, please enter your next move again" << endl;
                        cout << "What's your next move?" << endl;
                        cout << "Row:";
                        cin >> inputRow;
                        cout << "Column:";
                        cin >> inputCol;
                    }
                    while(!Game.placeMark(inputRow - 1, inputCol - 1)){ // If the grid is already occupied
                        cout << "CHOSEN GRID OCCUPIED, please enter your next move again" << endl;
                        cout << "What's your next move?" << endl;
                        cout << "Row:";
                        cin >> inputRow;
                        cout << "Column:";
                        cin >> inputCol;
                    }
                    Game.placeMark(inputRow - 1, inputCol - 1); // -1 to fit the index
                    Game.changePlayer();

                    if (Game.checkForWin()) { // If Player 1 wins
                        cout << "Player 2 wins!" << endl;
                        cout << "Play again? (y/n)" << endl;
                        cin >> playAgain;
                    }

                }
            }
        }
    }

    return 0;
}