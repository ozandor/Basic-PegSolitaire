#include <iostream>
#include "solitaire.h"
using namespace std;

int main(){

	int runGame = 1;

	cout << "\n\nWelcome to Peg Solitaire Game!\nYou can choose between 6 different boards or load and save custom boards.\nThese boards can be played by you or played by computer automatically.\nHave fun!\n" << endl;

	while(runGame){

		playSolitaire();
		
		cout << "\nWant to Quit Application?(0) or Play Again?(1) \nYour choice: ";
		cin >> runGame;

	}

	return 0;
}