#include "Board.h"
#include "HumanPlayer.h"
#include <iostream>

Board::Move HumanPlayer::makeMove(const Board& b) {
	
	std::cout << "Enter the move in the format a 6 or b 4 : ";
	char c;
	int v;
	std::cin >> c >> v;
	//make a new move, based on user's input
	Board::Move newMove(c, v);
	//while the move is not legal, prompt and repeat
	while (!b.isLegal(newMove)) {
		std::cout << "\nInvalid move. Please try again.\n";
		std::cout << "Enter the move in the format a 6 or b 4 : ";
		char c;
		int v;
		std::cin >> c >> v;
		Board::Move nM(c, v);
		newMove = nM;
	}
	//once legal, return the move
	return newMove;

}