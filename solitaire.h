#ifndef SOLITAIRE_H
#define SOLITAIRE_H

#include <iostream>
#include <vector>
#include <string>
#include <time.h> /* Used for the srand() function to pick random numbers. */
#include <fstream>
using namespace std;

void playSolitaire(); /* Basically, plays the game called Solitaire. */

int takeBoardTyp(); /* Takes the board choice of the user between 1-6 and returns it as int. */
int takePlayerTyp(); /* Takes the player type between 1-2(Human and Computer) and returns it as int. */
vector<vector<char>> fillBoard(int BoardType); /* Creates and returns a 2D vector filled with the elements of the expected board in the right order. */
void prntBoard(vector<vector<char>> vecBoard); /* Takes the created or updated 2D vector and prints the selected board to the console. */

int checkR(vector<vector<char>> vecBoard, int i, int j); /* Checks the validity of the move for the Right. If move is valid returns 1 else returns 0. */
int checkL(vector<vector<char>> vecBoard, int i, int j); /* Checks the validity of the move for the Left. If move is valid returns 1 else returns 0. */
int checkU(vector<vector<char>> vecBoard, int i, int j); /* Checks the validity of the move for the Up. If move is valid returns 1 else returns 0. */
int checkD(vector<vector<char>> vecBoard, int i, int j); /* Checks the validity of the move for the Down. If move is valid returns 1 else returns 0. */
int checkSides(vector<vector<char>> vecBoard, int i, int j); /* Checks the validity of the move for the ALL Sides. If move is valid for any way, returns 1 else returns 0. */
int checkCoord(vector<vector<char>> vecBoard, int i, int j); /* Checks the validity of the given coordinate. If there is a peg returns 1 and If there is not returns 0. */
int checkEnd(vector<vector<char>> vecBoard); /* Checks for the condition of the game. If game is ended returns 1, If game is not ended returns 0. */

vector<vector<char>> moveR(vector<vector<char>> vecBoard, int i, int j); /* Makes the move for Right side and returns updated vector board. */
vector<vector<char>> moveL(vector<vector<char>> vecBoard, int i, int j); /* Makes the move for Left side and returns updated vector board. */
vector<vector<char>> moveU(vector<vector<char>> vecBoard, int i, int j); /* Makes the move for Upside and returns updated vector board. */
vector<vector<char>> moveD(vector<vector<char>> vecBoard, int i, int j); /* Makes the move for Down and returns updated vector board. */

vector<vector<char>> getMoveUser(vector<vector<char>> vecBoard); /* Takes a command until the user enters a valid one and moves the peg to the user's wanted direction. */
vector<vector<char>> getMoveComputer(vector<vector<char>> vecBoard); /* Computer makes a random valid move. */

vector<vector<char>> continueGame(vector<vector<char>> vecBoard, int PlayerTyp); /* Takes a new command and moves the pegs until there is not any move left. */

void printScore(vector<vector<char>> vecBoard); /* Counts the all peg's that can not moveable then prints the number of them as the final score of the game. */

int checkRTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the checkR(). */
int checkLTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the checkL(). */
int checkUTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the checkU(). */
int checkDTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the checkD(). */
int checkSidesTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the checkSides(). */
int checkEndTri(vector<vector<char>> vecBoard); /* Triangle version of the checkEnd(). */

vector<vector<char>> moveRTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the moveR(). */
vector<vector<char>> moveLTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the moveL(). */
vector<vector<char>> moveUTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the moveU(). */
vector<vector<char>> moveDTri(vector<vector<char>> vecBoard, int i, int j); /* Triangle version of the moveD(). */

vector<vector<char>> getMoveUserTri(vector<vector<char>> vecBoard); /* Triangle version of the getMoveUser(). */
vector<vector<char>> getMoveComputerTri(vector<vector<char>> vecBoard); /* Triangle version of the getMoveComputer(). */

vector<vector<char>> continueGameTri(vector<vector<char>> vecBoard, int PlayerTyp); /* Triangle version of the continueGame(). */


int checkCommand(string userCommand, int commandLength = 4); /* Checks for the validity of the command user entered for save or load. If user entered command save or load returns 1, else returns 0. */
string getFileName(string& userCommand); /* Gets the name of the txt file from user's command string. */
void saveFile(const string& fileName, vector<vector<char>>& vecBoard); /* Saves the current game to the file as txt. */
vector<vector<char>> loadFile(const string& fileName); /* Loads the game from commanded txt file. */

#endif