/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include "Board.h";
#include "Game.h";
#include <iostream>


Board::Board() {
	//initialize board to empty for both enemy and player pieces
	reset();
	//keep track of hits or both players
	hitCountOne = 0;
	hitCountTwo = 0;
	count = 1; //begin with player 1 
}


void Board::reset() noexcept {

	//initialize an empty board
	for (int i = 0; i < 100; ++i) {
		player1[i] = Board::PlayerPiece::EMPTY;
		player2[i] = Board::PlayerPiece::EMPTY;

		enemy1[i] = Board::EnemyPiece::EMPTY;
		enemy2[i] = Board::EnemyPiece::EMPTY;
	}
}

//overload output for the playerpieces
std::ostream& operator << (std::ostream& out, Board::PlayerPiece p1) {

	switch (p1) {
	case Board::PlayerPiece::EMPTY: out << "-"; break;
	case Board::PlayerPiece::AIRCRAFT: out << "a"; break;
	case Board::PlayerPiece::BATTLESHIP: out << "b"; break;
	case Board::PlayerPiece::CRUISER: out << "c"; break;
	case Board::PlayerPiece::SUBMARINE: out << "s"; break;
	case Board::PlayerPiece::PATROL: out << "p"; break;
	case Board::PlayerPiece::HIT: out << "X"; break;

	}

	return out;
}
//overloaded output for the enemy pieces
std::ostream& operator << (std::ostream& out, Board::EnemyPiece e1) {

	switch (e1) {
	case Board::EnemyPiece::EMPTY: out << "-"; break;
	case Board::EnemyPiece::HIT: out << "X"; break;
	case Board::EnemyPiece::MISS: out << "O"; break; 
		
	}
	return out;
}

//display the appropriate boards or the appropriate players
void Board::display(int player) const noexcept {
	std::cout << "\nDisplaying PLAYER " << player << "'S BOARD\n";
	if (player == 1) {
		for (int i = 0; i < 100; ++i) {
			if (i % 10 == 0) {
				std::cout << "\n";
			}
			std::cout << Board::player1[i] << " ";
		}

		std::cout << "\nDisplaying PLAYER " << player+1 << "'S ENEMY BOARD\n";
		for (int i = 0; i < 100; ++i) {
			if (i % 10 == 0) {
				std::cout << "\n";
			}
			std::cout << Board::enemy2[i] << " ";
		}  

	}
	else {
		for (int i = 0; i < 100; ++i) {
			if (i % 10 == 0) {
				std::cout << "\n";
			}
			std::cout << Board::player2[i] << " ";
		}

		std::cout << "\nDisplaying PLAYER " << player-1 << "'S ENEMY'S BOARD\n";
		for (int i = 0; i < 100; ++i) {
			if (i % 10 == 0) {
				std::cout << "\n";
			}
			std::cout << Board::enemy1[i] << " ";
		}

	}
}

//make the appropriate moves, passed in as Moves
Board::EnemyPiece& Board::makeMove(const Board::Move& move) {
	//grab the index to play at 
	int index = move.indexVal;
	//if it is valid, make the move (otherwise, prompt user to repeat)
	if (isLegal(move)) {
		//if player 1
		if (count == 1) { 
			//update player2, if it is a hit
			if (player2[index] == Board::PlayerPiece::AIRCRAFT ||
				player2[index] == Board::PlayerPiece::SUBMARINE ||
				player2[index] == Board::PlayerPiece::PATROL ||
				player2[index] == Board::PlayerPiece::BATTLESHIP ||
				player2[index] == Board::PlayerPiece::CRUISER) {

				player2[index] = Board::PlayerPiece::HIT;
				enemy2[index] = Board::EnemyPiece::HIT;
				std::cout << "\nNice shot Player 1, that's a HIT!\n";
				hitCountOne++;
				count++; //player 2's turn next
				return enemy2[index];
			}
			else {
				//its a miss, so update the appropriate boards
				enemy2[index] = Board::EnemyPiece::MISS;
				std::cout << "\nKERSPLOOSH. You missed, Player 1!\n";
				count++;
				return enemy2[index];
			}
		}
		//if player2 playing
		else {
			if (player1[index] == Board::PlayerPiece::AIRCRAFT ||
				player1[index] == Board::PlayerPiece::SUBMARINE ||
				player1[index] == Board::PlayerPiece::PATROL ||
				player1[index] == Board::PlayerPiece::BATTLESHIP ||
				player1[index] == Board::PlayerPiece::CRUISER) {

				player1[index] = Board::PlayerPiece::HIT;
				enemy1[index] = Board::EnemyPiece::HIT;
				//update hits
				std::cout << "\nNice shot Player 2, that's a HIT!\n";
				hitCountTwo++;
				count--; //player 1's turn next
				return enemy1[index];
			}
			else {
				//player2 missed
				enemy1[index] = Board::EnemyPiece::MISS;
				count--;
				std::cout << "\nKERSPLOOSH. You missed, Player 2!\n";
				return enemy1[index];
			}

		}
	}
}


bool Board::isLegal(const Board::Move& m1) const noexcept {

	//incorrect char val
	if (m1.charVal < 'a' || m1.charVal > 'j') {
		return false; 
	}
	//incorrect index, important to check this first 
	if (m1.indexVal < 0 || m1.indexVal  > 99) {
		return false;
	} 

	//player 1's move, so check player 2's board for previous attacks
	if (count == 1) {
		
		if (player2[m1.indexVal] == Board::PlayerPiece::HIT ||
			enemy2[m1.indexVal] == Board::EnemyPiece::MISS) {
			std::cout << "You've already made that move Player 1. Try again.\n";
			return false; //they've already hit/tried to hit this location 
		}

	}
	else if (count == 2) {
		
		if (player1[m1.indexVal] == Board::PlayerPiece::HIT ||
			enemy1[m1.indexVal] == Board::EnemyPiece::MISS) {
			std::cout << "You've already made that move Player 2. Try again.\n";
			return false; //they've already hit!  
		}
	}

	//if not invalid letter, index, or repeated move, its valid
		return true; 
		

}

/*
For this implementation, it was assumed that AIRCRAFT correponds to the Carrier ship type in
the original Battleship game, thus, this value takes up 5 spaces. */
void Board::setShips() {

	//set aircraft locations for players 1 and 2 (note that both boards get differing locations)
	for (int i = 0; i < 5; ++i) {
		Board::player1[i] = Board::PlayerPiece::AIRCRAFT;
		Board::player2[i + 30] = Board::PlayerPiece::AIRCRAFT;
	}

	//set Battleship for both players (size 4)
	for (int j = 0; j < 4; ++j) {
		Board::player1[j+24] = Board::PlayerPiece::BATTLESHIP;
		Board::player2[j] = Board::PlayerPiece::BATTLESHIP;
	}

	//set Cruiser and subamrine locations for both players (size 3)
	int sizeCount = 0; 
	for (int c = 35; c < 56; c += 10) {
		Board::player1[c] = Board::PlayerPiece::CRUISER;
		if (sizeCount < 3) {
			Board::player1[c+44] = Board::PlayerPiece::SUBMARINE;
		}

		if (sizeCount < 3) {
			Board::player2[c - 28] = Board::PlayerPiece::CRUISER;
			Board::player2[c + 37] = Board::PlayerPiece::SUBMARINE;
			sizeCount++;
		}
	}
	//set the patrol boat locations (size 2)
	for (int p = 0; p < 2; ++p) {
		Board::player1[p + 8] = Board::PlayerPiece::PATROL;
		Board::player2[p + 85] = Board::PlayerPiece::PATROL;

	}

}


