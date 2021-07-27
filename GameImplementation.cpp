/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include "Game.h"
#include "RandomPlayer.h"
#include "HumanPlayer.h";
#include <iostream>

	//game constructor
	Game::Game() : player1(nullptr), player2(nullptr) {
		//set both player's to nullptr (done in intializer list
		//due to lack of default constructor in Player class)
		
		playerNumb = 1; //begin with player1

		Game::playerBoard.reset();
		Game::playerBoard.setShips(); // set the ships to 
		//avoid doing this in main
	}
	//deconstructor
	Game::~Game() {
		delete player1;
		delete player2; 
	}

	void Game::selectPlayers() {
		//user selects types of players
		std::cout << "\nSelect the two types of players. Press C for computer " <<
			"players and H for human: ";
		char val1, val2; 
		std::cin >> val1 >> val2; 
		//just in case user enters lowercase values
		val1 = toupper(val1);
		val2 = toupper(val2);

		//if user enters computer player for player1
		if (val1 == 'C') {
			player1 = new RandomPlayer();
			std::cout << "\nPlayer 1 Random Set: " << player1->getName() << std::endl;
		//if user enters human player for player1
		}  else if (val1 == 'H') {
			std::cout << "Player 1, please enter a name (greater than 1 char) for this human player: ";
			std::string n;
			std::cin >> n;
			player1 = new HumanPlayer(n);

			std::cout << "\nPlayer 1 Human Set: " << player1->getName() << std::endl;
		}
		else {
			std::cout << "Incorrect entry.";
			exit(1);
		}
		//if user enters computer player for player2
		if (val2 == 'C') {
			player2 = new RandomPlayer();
			std::cout << "Player 2 Random Set: " << player2->getName() << std::endl;
			//if user enters human player for player2
		} else if (val2 == 'H') {
			std::cout << "Player 2, please enter a name (greater than 1 char) for this human player: ";
			std::string n;
			std::cin >> n;
			player2 = new HumanPlayer(n);
			std::cout << "Player 2 Human Set: " << player2->getName() << std::endl;
		}
		else {
			std::cout << "Incorrect entry.";
			exit(1);
		}

	}

	//this method returns the player to the next player
	Player* Game::nextPlayer() const {
		
		//if player1
		if (playerNumb <= 1) {
			std::cout << "\nPlayer 1's turn.\n";
			return player1; //return the correct pointer
		}
		else {
			std::cout << "\nPlayer 2's turn.\n";
			return player2; 
		}

	}

	void Game::play() {
		//display the first board
		playerBoard.display(playerNumb);
	
		while (isRunning()) {
			//move to the next player
			Player* p = nextPlayer();
			//this updates player number value
			if (p == player1) {
				playerNumb++;
			}
			else {
				playerNumb--;
			}
			//create the move
			Board::Move mv = p->makeMove(playerBoard);
			//play the move
			playerBoard.makeMove(mv);
			//display the result
			playerBoard.display(playerNumb);
		
		}
	}

	//if either point gets more than 17 hits (the number of ship squares)
	void Game::announceWinner() {
		//if player 1 reaches 17 hits first, they win
		if (playerBoard.getHitCountOne() >= 17) {
			std::cout << "\n" << player1->getName() << " wins! CONGRATS " << player1->getName() << "!";
		}
		else {
			//otherwise player 2 wins
			std::cout << "\n" << player2->getName() << " wins! CONGRATS " << player2->getName() << "!";
		}

	}

	bool  Game::isRunning() {
		//runs while no player has won
		if (playerBoard.getHitCountOne() >= 17 || playerBoard.getHitCountTwo() >= 17) {
			return false;
		}
		return true; 
		
	}
