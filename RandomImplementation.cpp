#include "RandomPlayer.h"

Board::Move RandomPlayer::makeMove(const Board& b1) {
	//seed random generator
	std::mt19937 random(time(0)); //seed with current time

	std::uniform_int_distribution<int> genChar(97, 106); //these are the respective unicode
	//values from a to j
	//grab the random character
	int randChar = genChar(random);

	std::uniform_int_distribution<int> genIndex(0, 9); //get random index between 0 and 9
	int randIndex = genIndex(random);

	char randComputerChar = (char)randChar; //convert unicode to char
	Board::Move computerMove(randComputerChar, randIndex); //create new move 
	//while the move is not legal, simply create a new move
	while (!b1.isLegal(computerMove)) {

		//values from a to j
		int randChar = genChar(random);

		//new index
		randIndex = genIndex(random);

		randComputerChar = (char)randChar;

		Board::Move cM(randComputerChar, randIndex);
		computerMove = cM;
	}

	std::cout << "\nThe computer randomly selects " << randComputerChar << ", " << randIndex << ".\n";

	return computerMove; //return move

}
