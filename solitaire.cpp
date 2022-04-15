#include "solitaire.h"


void playSolitaire(){

	int PlayerTyp, BoardTyp;

	vector<vector<char>> vecBoard; /* Created a 2D vector for board. */

	BoardTyp = takeBoardTyp(); /* Takes the type of the board. */

	vecBoard = fillBoard(BoardTyp); /* Fills the board with wanted elements. */

	PlayerTyp = takePlayerTyp(); /* Takes the player type from user. */

	prntBoard(vecBoard); /* Printed the board we just made. */

	if( (BoardTyp > 0) && (BoardTyp < 6) ){ /* When BoardType is rectangle board type, */
	/* continues to game with normal directions. */
		vecBoard = continueGame(vecBoard, PlayerTyp); /* Continues to game until there is not any peg left to move. */
	
	}

	if(BoardTyp == 6){ /* When BoardType is a triangle board type, */
	/* continues to game with cross directions for up and down. */
		vecBoard = continueGameTri(vecBoard, PlayerTyp); /* Continues to game until there is not any peg left to move. */

	}

	printScore(vecBoard); /* When game ends prints the score. */

}


int takeBoardTyp(){

	int BoardTyp;

	cout << "\nPlease enter the type of the board (between 1-6) \n";
	cin >> BoardTyp;

	while( BoardTyp < 1 || BoardTyp > 6 ){ /* If user enters a false board type number, User will be warned and Board Type get from user until the right numbers entered. */

		cout << "\nYou entered a not existed board type. Please pick a board between 1-6 \n";
		cin >> BoardTyp;

	}

	return BoardTyp;

}


int takePlayerTyp(){

	int PlayerTyp;

	cout << "\nPlease select the player type:\n1-Human Player Game\n2-Computer Player Game\n";
	cin >> PlayerTyp;

	while( PlayerTyp < 1 || PlayerTyp > 2){ /* If user enters a false player type number, User will be warned until the user enters a valid number for player type. */

		cout << "\nYou entered a not existed player type. Please pick 1-Human 2-Computer (1 or 2)\n";
		cin >> PlayerTyp;
	}

	/* Makes the board that user picked between 1-6. */

	cout << "\nGame will be played by ";

	if(PlayerTyp == 1){

		cout << "Human Player.\n\n";

	}
	else if(PlayerTyp == 2){

		cout << "Computer Player.\n\n";

	}
	else{ /* If none of the conditions are made, there was a unknown error. Gives a warning about unknown condition. */

		cerr << "\nUnexpected error at player type! Reset the program. \n";

	}

	return PlayerTyp;

}


vector<vector<char>> fillBoard(int BoardType){

	/* Creates a 2D vector filled with the elements of the expected board in the right order. Then returns that vector. */

	if(BoardType == 1){

		vector<vector<char>> vecBoard{

			{'x','a','b','c','d','e','f','g'},
			{'1','x','x','P','P','P','x','x'},
			{'2','x','P','P','P','P','P','x'},
			{'3','P','P','P','.','P','P','P'},
			{'4','P','P','P','P','P','P','P'},
			{'5','P','P','P','P','P','P','P'},
			{'6','x','P','P','P','P','P','x'},
			{'7','x','x','P','P','P','x','x'}

		};

		return vecBoard;

	}
	else if(BoardType == 2){

		vector<vector<char>> vecBoard{

			{'x','a','b','c','d','e','f','g','h','i'},
			{'1','x','x','x','P','P','P','x','x','x'},
			{'2','x','x','x','P','P','P','x','x','x'},
			{'3','x','x','x','P','P','P','x','x','x'},
			{'4','P','P','P','P','P','P','P','P','P'},
			{'5','P','P','P','P','.','P','P','P','P'},
			{'6','P','P','P','P','P','P','P','P','P'},
			{'7','x','x','x','P','P','P','x','x','x'},
			{'8','x','x','x','P','P','P','x','x','x'},
			{'9','x','x','x','P','P','P','x','x','x'}
		
		};

		return vecBoard;

	}
	else if(BoardType == 3){

		vector<vector<char>> vecBoard{

			{'x','a','b','c','d','e','f','g','h'},
			{'1','x','x','P','P','P','x','x','x'},
			{'2','x','x','P','P','P','x','x','x'},
			{'3','x','x','P','P','P','x','x','x'},
			{'4','P','P','P','P','P','P','P','P'},
			{'5','P','P','P','.','P','P','P','P'},
			{'6','P','P','P','P','P','P','P','P'},
			{'7','x','x','P','P','P','x','x','x'},
			{'8','x','x','P','P','P','x','x','x'}
		
		};

		return vecBoard;
		
	}
	else if(BoardType == 4){

		vector<vector<char>> vecBoard{

			{'x','a','b','c','d','e','f','g'},
			{'1','x','x','P','P','P','x','x'},
			{'2','x','x','P','P','P','x','x'},
			{'3','P','P','P','P','P','P','P'},
			{'4','P','P','P','.','P','P','P'},
			{'5','P','P','P','P','P','P','P'},
			{'6','x','x','P','P','P','x','x'},
			{'7','x','x','P','P','P','x','x'}
		
		};

		return vecBoard;
		
	}
	else if(BoardType == 5){
		
		vector<vector<char>> vecBoard{

			{'x','a','b','c','d','e','f','g','h','i'},
			{'1','x','x','x','x','P','x','x','x','x'},
			{'2','x','x','x','P','P','P','x','x','x'},
			{'3','x','x','P','P','P','P','P','x','x'},
			{'4','x','P','P','P','P','P','P','P','x'},
			{'5','P','P','P','P','.','P','P','P','P'},
			{'6','x','P','P','P','P','P','P','P','x'},
			{'7','x','x','P','P','P','P','P','x','x'},
			{'8','x','x','x','P','P','P','x','x','x'},
			{'9','x','x','x','x','P','x','x','x','x'}
		
		};

		return vecBoard;

	}
	else if(BoardType == 6){
		
		vector<vector<char>> vecBoard{

			{'x','a','b','c','d','e','f','g','h','i'},
			{'1','x','x','x','x','.','x','x','x','x'},
			{'2','x','x','x','P','x','P','x','x','x'},
			{'3','x','x','P','x','P','x','P','x','x'},
			{'4','x','P','x','P','x','P','x','P','x'},
			{'5','P','x','P','x','P','x','P','x','P'}

		};


		return vecBoard;
	}

	vector<vector<char>> vecBoard{{'E','R','R','O','R',},{'!','!','!','!','!'}};

	cerr << "Unexpected error at declaring the board between 1-6";

	return vecBoard;

}


void prntBoard(vector<vector<char>> vecBoard){

	/* Takes the created 2D vector and prints the selected board to the console with 2D. Prints character 'x' as space(' ') character. */

	for(int i = 0; i < vecBoard.size(); ++i){

		for(int j = 0; j < vecBoard[i].size(); ++j){

			if(vecBoard[i][j] == 'x'){ /* For better view in console, we replace character 'x' with character ' '. */

				cout << " ";

			}
			else{ /* If character is not 'x' we directly print it to the console element by element. */

				cout << vecBoard[i][j];

			}

		}

		cout << "\n"; /* We print new line for the new raw of the vector. */

	}


}


int checkR(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (j + 1) >= vecBoard[i].size()){ /* Checks if j + 1 out of bounds of the 2D vector. */

			return 0;

		}
		
		if(vecBoard[i][j + 1] == 'P'){ /* and player's choice have a 'P' character at the right of it, */

			if( (j + 2) >= vecBoard[i].size()){ /* Checks if j + 2 out of bounds of the 2D vector. */

				return 0;

			}

			if(vecBoard[i][j + 2] == '.'){ /* and player's choice have a space ( '.' character) in the two right of it, */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;

}


int checkL(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (j - 1) < 0){ /* Checks if j - 1 out of bounds of the 2D vector. */

			return 0;

		}

		if(vecBoard[i][j - 1] == 'P'){ /* and player's choice have a 'P' character at the left of it, */

			if( (j - 2) < 0){ /* Checks if j - 2 out of bounds of the 2D vector. */

				return 0;

			}

			if(vecBoard[i][j - 2] == '.'){ /* and player's choice have a space ( '.' character) in the two left of it, */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;

}


int checkU(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (i - 1) < 0){ /* Checks if i - 1 out of bounds of the 2D vector. */

			return 0;

		}

		if(vecBoard[i - 1][j] == 'P'){ /* and player's choice have a 'P' character at the upside of it, */

			if( (i - 2) < 0){ /* Checks if i - 2 out of bounds of the 2D vector. */

				return 0;

			}

			if(vecBoard[i - 2][j] == '.'){ /* and player's choice have a space ( '.' character) in the two upside of it, */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;

}


int checkD(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (i + 1) >= vecBoard.size()){ /* Checks if i + 1 out of bounds of the 2D vector. */

			return 0;

		}

		if(vecBoard[i + 1][j] == 'P'){ /* and player's choice have a 'P' character at the down of it, */

			if( (i + 2) >= vecBoard.size()){ /* Checks if i + 2 out of bounds of the 2D vector. */

				return 0;

			}

			if(vecBoard[i + 2][j] == '.'){ /* and player's choice have a space ( '.' character) in the two down of it, */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;

}


int checkSides(vector<vector<char>> vecBoard, int i, int j){ 

	if(checkR(vecBoard,i,j) == 1){ /* If point is valid to move Right, there is still moves to do. */

		return 1;

	}

	if(checkL(vecBoard,i,j) == 1){ /* If point is valid to move Left, there is still moves to do. */

		return 1;

	}
	
	if(checkU(vecBoard,i,j) == 1){ /* If point is valid to move Upside, there is still moves to do. */

		return 1;

	}

	if(checkD(vecBoard,i,j) == 1){ /* If point is valid to move Down, there is still moves to do.*/

		return 1;

	}
	/* If down is not a valid move for point, this means all sides are not available. There is not any move to do for this point. */

	return 0;

}


int checkCoord(vector<vector<char>> vecBoard, int i, int j){

	if(i < 0 || i >= vecBoard.size()){ /* Checks if i out of bounds of the 2D vector. */

		return 0;

	}

	if(j < 0 || j >= vecBoard[i].size()){ /* Checks if j out of bounds of the 2D vector. */

		return 0;

	}

	if(vecBoard[i][j] == 'P'){  /* If there is a peg in the wanted coordinate we return 1, */

		return 1;

	}

	return 0;

}


vector<vector<char>> moveR(vector<vector<char>> vecBoard, int i, int j){

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i][j + 1] = '.'; /* Replaces the peg at the right of the selected point's peg with space. */
	vecBoard[i][j + 2] = 'P'; /* Replaces the space at the two right of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> moveL(vector<vector<char>> vecBoard, int i, int j){

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i][j - 1] = '.'; /* Replaces the peg at the left of the selected point's peg with space. */
	vecBoard[i][j - 2] = 'P'; /* Replaces the space at the two left of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> moveU(vector<vector<char>> vecBoard, int i, int j){

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i - 1][j] = '.'; /* Replaces the peg at the upside of the selected point's peg with space. */
	vecBoard[i - 2][j] = 'P'; /* Replaces the space at the two upside of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> moveD(vector<vector<char>> vecBoard, int i, int j){

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i + 1][j] = '.'; /* Replaces the peg at the down of the selected point's peg with space. */
	vecBoard[i + 2][j] = 'P'; /* Replaces the space at the two down of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> getMoveUser(vector<vector<char>> vecBoard){

	string userMoveInp; /* String that we get by user. */
	int column,raw,way;
	int validInp; /* Checks the validity of the input. */
	string fileName; /* Used to hold the name of the file to load or save from.  */

	cout << "\nPlease enter the command as example: A1-R \ncolumn(letter with uppercase) raw(number) '-' character and the way you want to move\n(R for right, L for left, U for upside, D for down.)";
	
	cout << "\n\nIf you want to save current game use command: save filename.txt\nIf you want to load a game use command: load filename.txt\n(Only load direct movement boards.)\n\n";

	do{

		cout << "\nCommand:";
		cin	>> userMoveInp; /* Gets the input from user. */

		if(checkCommand(userMoveInp)){ /* Firstly checks for commands existance as save or load, */
		/* If user used a save or load command, */

			fileName = getFileName(userMoveInp); /* Takes the file name from command. */ 

			if(userMoveInp[0] == 's'){ /* If command is save. */

				saveFile(fileName, vecBoard); /* Saves the game to txt with commanded name. */

				validInp = 1;

				cout << "\nGame is saved to the file named: " << fileName << endl;

			}
			else if(userMoveInp[0] == 'l'){ /*If command is load. */

				vecBoard = loadFile(fileName); /* Loads game from the txt with commanded name. */

				validInp = 1;

				cout << "\nGame is loaded from the file named: " << fileName << endl;

			}
			else{

				cerr << "\nYou used the save or load command false. Try again.\n";

				validInp = 0;

			}


		}
		else if(userMoveInp[0] < 'A' || userMoveInp[0] > 'Z'){ /* If user not enters a capital letter as a first char of the input, the input is not valid. */

			cout << "\nPlease enter the column first in your command as a capital letter.\n";

			validInp = 0;

		}
		else{ /* If user entered the column part correct, */

			if(userMoveInp[1] < '1' || userMoveInp[1] > '9'){ /* If user enters a not existed number for the coordinate, input is not valid.*/

				cout << "\nPlease enter the raw secondly in your command between 1-9 (including 1 and 9).\n";

				validInp = 0;

			}
			else{ /* If user entered the first 2 char correct, */

				if(userMoveInp[2] != '-'){ /* If user not enters the character '-' as the 3. character, input is not valid. */

					cout << "\nPlease enter '-' character as 3.character of your command.\n";

					validInp = 0;

				}
				else{ /* If user entered the first 3 part correctly. */

					if( (userMoveInp[3] != 'R') && (userMoveInp[3] != 'L') && (userMoveInp[3] != 'U') && (userMoveInp[3] != 'D') ){ /* If user entered the way of the move false, input is invalid. */

						cout << "\nPlease enter the direction of the move as fourth character with capital letters.\n(R or L or U or D)\n";

						validInp = 0;

					}
					else{ /* If user entered the first 4 characters correctly, the command is valid. But lastly checks the coordinate for the peg's existance. */
						
						char at = '@';
						/* 
						**  In ascii, after the character '@' the capital letters comes. Normally A's value is 65 and @'s value is 64 so 
						** if we substract the value of the @ from the first capital letter, we get our coordinate we need. 
						** It is not depends from compiler to compiler becuse always after the char @ the char A comes. 
						*/
						column = (int)userMoveInp[0] - (int)at; 
						
						char zeroCh = '0'; /* Same logic with the at calculation*/

						raw = (int)userMoveInp[1] - (int)zeroCh;
						
						way = userMoveInp[3];

						if(checkCoord(vecBoard,raw,column) == 0){ /* If there is not peg in the given coordinate, */

							cout << "\nThere is not any peg in the given coordinate. Please enter the command again.\n";

							validInp = 0;

						}
						else if(checkCoord(vecBoard,raw,column) == 1){ /* If there is a peg in the given coordinate. */

							if(way == 'R'){ /* If the direction of the move is right,*/

								if(checkR(vecBoard,raw,column)){ /* If peg is moveable to right, */

									vecBoard = moveR(vecBoard,raw,column); /* Moves it to right. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to right, */

									cout << "\nThis peg can't move to right. Enter a command with available move.\n";

									validInp = 0;

								}

							}
							else if(way == 'L'){ /* If the direction of the move is left, */

								if(checkL(vecBoard,raw,column)){ /* If peg is moveable to left, */

									vecBoard = moveL(vecBoard,raw,column); /* Moves it to left. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to left, */

									cout << "\nThis peg can't move to left. Enter a command with available move.\n";

									validInp = 0;

								}

							}
							else if(way == 'U'){ /* If the direction of the move is up, */

								if(checkU(vecBoard,raw,column)){ /* If peg is moveable to up, */

									vecBoard = moveU(vecBoard,raw,column); /* Moves it to up. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to up, */

									cout << "\nThis peg can't move to up. Enter a command with available move.\n";

									validInp = 0;

								}

							}
							else if(way == 'D'){ /* If the direction of the move is down, */

								if(checkD(vecBoard,raw,column)){ /* If peg is moveable to down, */

									vecBoard = moveD(vecBoard,raw,column); /* Moves it to down. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to down, */

									cout << "\nThis peg can't move to down. Enter a command with available move.\n";

									validInp = 0;

								}

							}


						}
						else{ /* If there is unexpected error at the coordinate, */

							cout << "\nThere is unexpected error in the coordinate, please give the command again.\n";

							validInp = 0;

						}

					}

				}


			}

		}


	}while(validInp == 0);

	cout << "\nMove is done!\n\n";

	return vecBoard;

}


vector<vector<char>> continueGame(vector<vector<char>> vecBoard, int PlayerTyp){
	
	while( checkEnd(vecBoard) == 0 ){ /* While game is not ended, (There is still move/s to do.) */
		
		if(PlayerTyp == 1){ /* If player is a human. */
		/* Continue the game with getting a new command from human player. */
			
			vecBoard = getMoveUser(vecBoard);

		}
		else if(PlayerTyp == 2){ /* If player is a computer. */
		/* Continue the game with getting a new command from computer player. */

			vecBoard = getMoveComputer(vecBoard);

		}
		
		prntBoard(vecBoard); /* Prints the command's result to the screen. */

	}

	/* When this line is reached, this means we exit the while loop and there is no any available moves to do. */
	cout << "\nThere is not any moves left. Game is ended.\n\n";

	return vecBoard;

}


int checkEnd(vector<vector<char>> vecBoard){

	for(int i = 0; i < vecBoard.size(); ++i){ /* Scans the all the raws, */
	
		for(int j = 0; j < vecBoard[i].size(); ++j){ /* Scans the all columns, */

			if( checkSides(vecBoard,i,j) == 1 ){ /* Checks the all sides ability to move and if it detects for any way, */
				/* It means there is still move can be done, this means game is not ended yet. */
					
				return 0;

			}

		}

	}

	/* If this line is reached, this means all the pegs and board checked and there is not any move to do. This means game is ended. */

	return 1;

}


void printScore(vector<vector<char>> vecBoard){

	int score = 0;

	for(int i = 0; i < vecBoard.size(); ++i){ /* Scans all the raws. */

		for(int j = 0; j < vecBoard[i].size(); ++j){ /* Scans all the columns. */

			if( checkCoord(vecBoard, i, j) ){ /* Checks the coordinate of the point for the peg's existance. */
			/* If there is a peg adds this peg to the score by one point. */

				score++; 

			}

		}

	}

	cout << "\nYour score: " << score << endl;

	if( score == 1 ){

		cout << "\nWell done! You win the game.\n";

	}
	else{

		cout << "\nNice try! You can do better next time.\n\n";
	}


}


vector<vector<char>> getMoveComputer(vector<vector<char>> vecBoard){

	vector<int> coordValidX; /*  Holds the x coordinates of the valid moveable peg's in the board. */
	vector<int> coordValidY; /*  Holds the y coordinates of the valid moveable peg's in the board. */

	char chOne; /* Holds the command's first character (column) to show the move maded by computer. */
	char chTwo; /* Holds the command's second character (raw) to show the move maded by computer. */
	char chWay; /* Holds the command's last character (way) to show the move maded by computer. */

	for(int i = 0; i < vecBoard.size(); ++i){

		for(int j = 0; j < vecBoard[i].size(); ++j){

			if( checkSides(vecBoard, i, j) ){

				coordValidX.push_back(i); /* Assigns the moveable peg's X coordinate to vector. */
				coordValidY.push_back(j); /* Assigns the moveable peg's Y coordinate to vector. */

			}

		}

	}

	srand(time(NULL)); /* Used to get really random numbers. */

	int randPegNo = (rand() % coordValidX.size()); /* Randomly selects a number between 0 and moveable peg number. */
	int randWayNo = (rand() % 4); /* Randomly selects a way between 0 and 3. ( 0 = Right, 1 = Left, 2 = Up, 3 = Down. ) */

	int moveDoneable = 0; /* If the randomly selected way is valid exits the loop of random way taking. */
	int rVal = 1, lVal = 1, uVal = 1, dVal = 1; /* With random way selection, we do not now which side is valid. So at first we take all sides valid and if they are not we take a way randomly again until the valid one comes. */

	do{

		if(randWayNo == 0 && rVal == 1){ /* If way is right and r is still can be valid move, */

			if(checkR(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go right. */

				vecBoard = moveR(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to right. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'R';

			}
			else{ /* If right is checked and not valid, we assign the rVal to 0 for faster checks in the next repeats of the loop. */

				rVal = 0;

			}

		}
		else if(randWayNo == 1 && lVal == 1){ /* If way is left and l is still can be valid move, */

			if(checkL(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go left. */

				vecBoard = moveL(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to left. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'L';

			}
			else{ /* If left is checked and not valid, we assign the lVal to 0 for faster checks in the next repeats of the loop. */

				lVal = 0;

			}

		}
		else if(randWayNo == 2 && uVal == 1){ /* If way is Up and u is still can be valid move, */

			if(checkU(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go up. */

				vecBoard = moveU(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to up. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'U';

			}
			else{ /* If up is checked and not valid, we assign the uVal to 0 for faster checks in the next repeats of the loop. */

				uVal = 0;

			}

		}
		else if(randWayNo == 3 && dVal == 1){ /* If way is Down and d is still can be valid move, */

			if(checkD(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go down. */

				vecBoard = moveD(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to down. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'D';

			}
			else{ /* If down is checked and not valid, we assign the dVal to 0 for faster checks in the next repeats of the loop. */

				dVal = 0;

			}

		}
		

		/* When this line reached, a way can be not valid so we assign a new way randomly again until we made the valid move and exit the loop. */
		randWayNo = (rand() % 4); /* Randomly selects a new way between 0 and 3. ( 0 = Right, 1 = Left, 2 = Up, 3 = Down. ) */

	}while(moveDoneable == 0);
	
	char at = '@'; /* Used to convert the column coordinate to a uppercase letter. */

	chOne = (char)coordValidY[randPegNo] + at; /* Column coordinate as uppercase letter. */

	chTwo = (char)coordValidX[randPegNo]; /* Raw coordinate. (Converted to int while printing.) */

	cout << "\nComputer commanded the move: " << chOne << (int)chTwo << "-" << chWay << "\n\n";

	cout << "Updated Board:\n\n";

	return vecBoard;

}

/* Next functions used for the mechanism of the board 6. */

int checkRTri(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (j + 2) >= vecBoard[i].size()){ /* Checks if j + 2 out of bounds of the 2D vector. */

			return 0;

		}
		
		if(vecBoard[i][j + 2] == 'P'){ /* and player's choice have a 'P' character at the right of it, */

			if( (j + 4) >= vecBoard[i].size()){ /* Checks if j + 4 out of bounds of the 2D vector. */

				return 0;

			}

			if(vecBoard[i][j + 4] == '.'){ /* and player's choice have a space ( '.' character) in the two right of it, */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;

}


int checkLTri(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (j - 2) < 0){ /* Checks if j - 2 out of bounds of the 2D vector. */

			return 0;

		}

		if(vecBoard[i][j - 2] == 'P'){ /* and player's choice have a 'P' character at the left of it, */

			if( (j - 4) < 0){ /* Checks if j - 4 out of bounds of the 2D vector. */

				return 0;

			}

			if(vecBoard[i][j - 4] == '.'){ /* and player's choice have a space ( '.' character) in the two left of it, */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;


}


int checkUTri(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (i - 1) < 0){ /* Checks if i - 1 out of bounds of the 2D vector. (Only the upside can be out of the bounds for move up.) */

			return 0;

		}

		if(vecBoard[i - 1][j + 1] == 'P'){ /* and player's choice have a 'P' character at the upside of it, (Upside moves to right-up.) */

			if( (i - 2) < 0){ /* Checks if i - 2 out of bounds of the 2D vector. (Only the upside can be out of the bounds for move up.) */

				return 0;

			}

			if(vecBoard[i - 2][j + 2] == '.'){ /* and player's choice have a space ( '.' character) in the two upside of it, (Upside moves to right-up.) */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;

}


int checkDTri(vector<vector<char>> vecBoard, int i, int j){

	if(vecBoard[i][j] == 'P'){ /* If player holded the 'P' character, */

		if( (i + 1) >= vecBoard.size()){ /* Checks if i + 1 out of bounds of the 2D vector. (Only the downside can be out of the bounds for move down.) */

			return 0;

		}

		if(vecBoard[i + 1][j - 1] == 'P'){ /* and player's choice have a 'P' character at the down of it, (Downside moves to left-down.) */

			if( (i + 2) >= vecBoard.size()){ /* Checks if i + 2 out of bounds of the 2D vector. (Only the downside can be out of the bounds for move down.) */

				return 0;

			}

			if(vecBoard[i + 2][j - 2] == '.'){ /* and player's choice have a space ( '.' character) in the two down of it, (Downside moves to left-down.) */
			/* move is valid. */	

				return 1;

			}

		}

	}

	return 0;

}


int checkSidesTri(vector<vector<char>> vecBoard, int i, int j){

	if(checkRTri(vecBoard,i,j) == 1){ /* If point is valid to move Right, there is still moves to do. */

		return 1;

	}

	if(checkLTri(vecBoard,i,j) == 1){ /* If point is valid to move Left, there is still moves to do. */

		return 1;

	}
	
	if(checkUTri(vecBoard,i,j) == 1){ /* If point is valid to move Upside, there is still moves to do. */

		return 1;

	}

	if(checkDTri(vecBoard,i,j) == 1){ /* If point is valid to move Down, there is still moves to do.*/

		return 1;

	}
	/* If down is not a valid move for point, this means all sides are not available. There is not any move to do for this point. */

	return 0;

}


int checkEndTri(vector<vector<char>> vecBoard){

	for(int i = 0; i < vecBoard.size(); ++i){ /* Scans the all the raws, */
	
		for(int j = 0; j < vecBoard[i].size(); ++j){ /* Scans the all columns, */

			if( checkSidesTri(vecBoard,i,j) == 1 ){ /* Checks the all sides ability to move and if it detects for any way, */
				/* It means there is still move can be done, this means game is not ended yet. */
					
				return 0;

			}

		}

	}

	/* If this line is reached, this means all the pegs and board checked and there is not any move to do. This means game is ended. */

	return 1;

}


vector<vector<char>> moveRTri(vector<vector<char>> vecBoard, int i, int j){

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i][j + 2] = '.'; /* Replaces the peg at the right of the selected point's peg with space. */
	vecBoard[i][j + 4] = 'P'; /* Replaces the space at the two right of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> moveLTri(vector<vector<char>> vecBoard, int i, int j){

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i][j - 2] = '.'; /* Replaces the peg at the left of the selected point's peg with space. */
	vecBoard[i][j - 4] = 'P'; /* Replaces the space at the two left of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> moveUTri(vector<vector<char>> vecBoard, int i, int j){ /* Upside moves the direction of right-up. */

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i - 1][j + 1] = '.'; /* Replaces the peg at the upside of the selected point's peg with space. */
	vecBoard[i - 2][j + 2] = 'P'; /* Replaces the space at the two upside of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> moveDTri(vector<vector<char>> vecBoard, int i, int j){ /* Downside moves the direction of left-down. */

	vecBoard[i][j] = '.'; /* Replaces the selected point's peg with space. */
	vecBoard[i + 1][j - 1] = '.'; /* Replaces the peg at the down of the selected point's peg with space. */
	vecBoard[i + 2][j - 2] = 'P'; /* Replaces the space at the two down of the selected point's peg with peg. */

	return vecBoard; /* Returns the new 2D vector board. */ 

}


vector<vector<char>> getMoveUserTri(vector<vector<char>> vecBoard){

	string userMoveInp; /* String that we get by user. */
	int column,raw,way;
	int validInp; /* Checks the validity of the input. */
	string fileName; /* Used to hold the name of the file to load or save from.  */

	cout << "\nPlease enter the command as example: A1-R \ncolumn(letter with uppercase) raw(number) '-' character and the way you want to move\n(R for right, L for left, U for upside(Right-Up direction), D for down(Left-Down direction). \n";
	
	cout << "\n\nIf you want to save current game use command: save filename.txt\nIf you want to load a game use command: load filename.txt\n(Only load cross movement boards.)\n\n";

	do{

		cout << "\nCommand:";
		cin	>> userMoveInp; /* Gets the input from user. */

		if(checkCommand(userMoveInp)){ /* Firstly checks for commands existance as save or load, */
		/* If user used a save or load command, */

			fileName = getFileName(userMoveInp); /* Takes the file name from command. */ 

			if(userMoveInp[0] == 's'){ /* If command is save. */

				saveFile(fileName, vecBoard); /* Saves the game to txt with commanded name. */

				validInp = 1;

				cout << "\nGame is saved to the file named: " << fileName << endl;

			}
			else if(userMoveInp[0] == 'l'){ /*If command is load. */

				vecBoard = loadFile(fileName); /* Loads game from the txt with commanded name. */

				validInp = 1;

				cout << "\nGame is loaded from the file named: " << fileName << endl;

			}
			else{

				cerr << "\nYou used the save or load command false. Try again.\n";

				validInp = 0;

			}


		}
		else if(userMoveInp[0] < 'A' || userMoveInp[0] > 'Z'){ /* If user not enters a capital letter as a first char of the input, the input is not valid. */

			cout << "\nPlease enter the column first in your command as a capital letter.\n";

			validInp = 0;

		}
		else{ /* If user entered the column part correct, */

			if(userMoveInp[1] < '1' || userMoveInp[1] > '9'){ /* If user enters a not existed number for the coordinate, input is not valid.*/

				cout << "\nPlease enter the raw secondly in your command between 1-9 (including 1 and 9).\n";

				validInp = 0;

			}
			else{ /* If user entered the first 2 char correct, */

				if(userMoveInp[2] != '-'){ /* If user not enters the character '-' as the 3. character, input is not valid. */

					cout << "\nPlease enter '-' character as 3.character of your command.\n";

					validInp = 0;

				}
				else{ /* If user entered the first 3 part correctly. */

					if( (userMoveInp[3] != 'R') && (userMoveInp[3] != 'L') && (userMoveInp[3] != 'U') && (userMoveInp[3] != 'D') ){ /* If user entered the way of the move false, input is invalid. */

						cout << "\nPlease enter the direction of the move as fourth character with capital letters.\n(R or L or U or D)\n";

						validInp = 0;

					}
					else{ /* If user entered the first 4 characters correctly, the command is valid. But lastly checks the coordinate for the peg's existance. */
						
						char at = '@';
						/* 
						**  In ascii, after the character '@' the capital letters comes. Normally A's value is 65 and @'s value is 64 so 
						** if we substract the value of the @ from the first capital letter, we get our coordinate we need. 
						** It is not depends from compiler to compiler becuse always after the char @ the char A comes. 
						*/
						column = (int)userMoveInp[0] - (int)at; 
						
						char zeroCh = '0'; /* Same logic with the at calculation*/

						raw = (int)userMoveInp[1] - (int)zeroCh;
						
						way = userMoveInp[3];

						if(checkCoord(vecBoard,raw,column) == 0){ /* If there is not peg in the given coordinate, */

							cout << "\nThere is not any peg in the given coordinate. Please enter the command again.\n";

							validInp = 0;

						}
						else if(checkCoord(vecBoard,raw,column) == 1){ /* If there is a peg in the given coordinate. */

							if(way == 'R'){ /* If the direction of the move is right,*/

								if(checkRTri(vecBoard,raw,column)){ /* If peg is moveable to right, */

									vecBoard = moveRTri(vecBoard,raw,column); /* Moves it to right. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to right, */

									cout << "\nThis peg can't move to right. Enter a command with available move.\n";

									validInp = 0;

								}

							}
							else if(way == 'L'){ /* If the direction of the move is left, */

								if(checkLTri(vecBoard,raw,column)){ /* If peg is moveable to left, */

									vecBoard = moveLTri(vecBoard,raw,column); /* Moves it to left. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to left, */

									cout << "\nThis peg can't move to left. Enter a command with available move.\n";

									validInp = 0;

								}

							}
							else if(way == 'U'){ /* If the direction of the move is up, */

								if(checkUTri(vecBoard,raw,column)){ /* If peg is moveable to up, */

									vecBoard = moveUTri(vecBoard,raw,column); /* Moves it to up. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to up, */

									cout << "\nThis peg can't move to up. Enter a command with available move.\n";

									validInp = 0;

								}

							}
							else if(way == 'D'){ /* If the direction of the move is down, */

								if(checkDTri(vecBoard,raw,column)){ /* If peg is moveable to down, */

									vecBoard = moveDTri(vecBoard,raw,column); /* Moves it to down. */

									validInp = 1; /* Input becomes valid, (Ends loop) */

								}
								else{ /* If peg is not moveable to down, */

									cout << "\nThis peg can't move to down. Enter a command with available move.\n";

									validInp = 0;

								}

							}


						}
						else{ /* If there is unexpected error at the coordinate, */

							cout << "\nThere is unexpected error in the coordinate, please give the command again.\n";

							validInp = 0;

						}

					}

				}


			}

		}


	}while(validInp == 0);

	cout << "\nMove is done!\n\n";

	return vecBoard;

}


vector<vector<char>> getMoveComputerTri(vector<vector<char>> vecBoard){

	vector<int> coordValidX; /*  Holds the x coordinates of the valid moveable peg's in the board. */
	vector<int> coordValidY; /*  Holds the y coordinates of the valid moveable peg's in the board. */

	char chOne; /* Holds the command's first character (column) to show the move maded by computer. */
	char chTwo; /* Holds the command's second character (raw) to show the move maded by computer. */
	char chWay; /* Holds the command's last character (way) to show the move maded by computer. */

	for(int i = 0; i < vecBoard.size(); ++i){

		for(int j = 0; j < vecBoard[i].size(); ++j){

			if( checkSidesTri(vecBoard, i, j) ){

				coordValidX.push_back(i); /* Assigns the moveable peg's X coordinate to vector. */
				coordValidY.push_back(j); /* Assigns the moveable peg's Y coordinate to vector. */

			}

		}

	}

	srand(time(NULL)); /* Used to get really random numbers. */

	int randPegNo = (rand() % coordValidX.size()); /* Randomly selects a number between 0 and moveable peg number. */
	int randWayNo = (rand() % 4); /* Randomly selects a way between 0 and 3. ( 0 = Right, 1 = Left, 2 = Up, 3 = Down. ) */

	int moveDoneable = 0; /* If the randomly selected way is valid exits the loop of random way taking. */
	int rVal = 1, lVal = 1, uVal = 1, dVal = 1; /* With random way selection, we do not now which side is valid. So at first we take all sides valid and if they are not we take a way randomly again until the valid one comes. */

	do{

		if(randWayNo == 0 && rVal == 1){ /* If way is right and r is still can be valid move, */

			if(checkRTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go right. */

				vecBoard = moveRTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to right. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'R';

			}
			else{ /* If right is checked and not valid, we assign the rVal to 0 for faster checks in the next repeats of the loop. */

				rVal = 0;

			}

		}
		else if(randWayNo == 1 && lVal == 1){ /* If way is left and l is still can be valid move, */

			if(checkLTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go left. */

				vecBoard = moveLTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to left. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'L';

			}
			else{ /* If left is checked and not valid, we assign the lVal to 0 for faster checks in the next repeats of the loop. */

				lVal = 0;

			}

		}
		else if(randWayNo == 2 && uVal == 1){ /* If way is Up and u is still can be valid move, */

			if(checkUTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go up. */

				vecBoard = moveUTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to up. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'U';

			}
			else{ /* If up is checked and not valid, we assign the uVal to 0 for faster checks in the next repeats of the loop. */

				uVal = 0;

			}

		}
		else if(randWayNo == 3 && dVal == 1){ /* If way is Down and d is still can be valid move, */

			if(checkDTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo])){ /* Checks the randomly selected valid peg's ability to go down. */

				vecBoard = moveDTri(vecBoard, coordValidX[randPegNo], coordValidY[randPegNo]); /* Moves the randomly selected valid peg to down. */

				moveDoneable = 1; /* When this move done, exits the loop. */

				chWay = 'D';

			}
			else{ /* If down is checked and not valid, we assign the dVal to 0 for faster checks in the next repeats of the loop. */

				dVal = 0;

			}

		}
		

		/* When this line reached, a way can be not valid so we assign a new way randomly again until we made the valid move and exit the loop. */
		randWayNo = (rand() % 4); /* Randomly selects a new way between 0 and 3. ( 0 = Right, 1 = Left, 2 = Up, 3 = Down. ) */

	}while(moveDoneable == 0);
	
	char at = '@'; /* Used to convert the column coordinate to a uppercase letter. */

	chOne = (char)coordValidY[randPegNo] + at; /* Column coordinate as uppercase letter. */

	chTwo = (char)coordValidX[randPegNo]; /* Raw coordinate. (Converted to int while printing.) */

	cout << "\nComputer commanded the move: " << chOne << (int)chTwo << "-" << chWay << "\n\n";

	cout << "Updated Board:\n\n";

	return vecBoard;

}


vector<vector<char>> continueGameTri(vector<vector<char>> vecBoard, int PlayerTyp){
	
	while( checkEndTri(vecBoard) == 0 ){ /* While game is not ended, (There is still move/s to do.) */
		
		if(PlayerTyp == 1){ /* If player is a human. */
		/* Continue the game with getting a new command from human player. */
			
			vecBoard = getMoveUserTri(vecBoard);

		}
		else if(PlayerTyp == 2){ /* If player is a computer. */
		/* Continue the game with getting a new command from computer player. */

			vecBoard = getMoveComputerTri(vecBoard);

		}
		
		prntBoard(vecBoard); /* Prints the command's result to the screen. */

	}

	/* When this line is reached, this means we exit the while loop and there is no any available moves to do. */
	cout << "\nThere is not any moves left. Game is ended.\n\n";

	return vecBoard;

}


int checkCommand(string userCommand, int commandLength){ /* Command length used as default argument in library. */
	
	decltype(commandLength) zero = 0,one = 1,two = 2; /* They have the same type with commandLength. */
	auto last = commandLength - 1; /* Place of the last character of the command taken as last and auto makes last int in this case. */
	
	if(userCommand.at(zero) == 's' && userCommand.at(one) == 'a' && userCommand.at(two) == 'v' && userCommand.at(last) == 'e'){

		return 1;

	}

	if(userCommand.at(zero) == 'l' && userCommand.at(one) == 'o' && userCommand.at(two) == 'a' && userCommand.at(last) == 'd'){

		return 1;

	}

	return 0;

}


string getFileName(string& userCommand){

	string fileName;

	cin >> fileName; /* Gets the file name used after the command. (Example: move example.txt. First cin takes move and when cin used again we take the example.txt part.) */

	return fileName;

}


void saveFile(const string& fileName, vector<vector<char>>& vecBoard){

	ofstream oFile;

	oFile.open(fileName);

	if(oFile.fail()){

		cerr << "Error at the opening the save file.\n\n";

		exit(1);

	}

	for(int i = 0; i < vecBoard.size(); ++i){

		for(int j = 0; j < vecBoard[i].size(); ++j){

			oFile << vecBoard[i][j];

		}

		oFile << "\n";

	}



	oFile.close();

}


vector<vector<char>> loadFile(const string& fileName){

	ifstream iFile; 
	vector<vector<char>> vecBoard; /* 2D vector board for game readed from file. */
	vector<char> vecTemp;
	string oneLine; /* Temp one line readed from file. */

	iFile.open(fileName);

	if(iFile.fail()){

		cerr << "Error at the opening the load file.\n\n";

		exit(1);

	}

	int i = 0; /* While getting the vectors, we need to start from the first row. */

	while(!iFile.eof()){

		getline(iFile, oneLine); /* Gets a line from file. */

		for(int j = 0; j < oneLine.size(); ++j){ /* Pushes all characters of the oneLine to the vector column by column. */
			
			vecTemp.push_back(oneLine.at(j)); /* Places the first line to the temporary vector. */

		}

		vecBoard.push_back(vecTemp); /* Places that vector to the 2D vector's row part. */

		++i; /* Goes to the next row. */

		/* Clear functions to prevent segmentation errors. */
		oneLine.clear();

		vecTemp.clear();

	}


	iFile.close();
	
	return vecBoard;

}