/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include "Player.h"

#ifndef GAME_H
#define GAME_H

class Game {

public: 
	//function declarations (see implementation for defintions)
	Game();
	~Game();
	void selectPlayers();
	Player* nextPlayer() const; 
	void play();
	void announceWinner();
	bool isRunning();
	//return the player number
	inline int getCurrentPlayer() { return playerNumb;  }
	


private: 
	Player* player1; //pointer to player1
	Player* player2; //pointer to player2

	int playerNumb; //player Number
	Board playerBoard; //the board 

};
#endif