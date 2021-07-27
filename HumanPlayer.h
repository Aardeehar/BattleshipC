/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include <iostream>
#include "Player.h"
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

class HumanPlayer : public Player {

public: 
	//call to the super constructor
	HumanPlayer(const std::string& s) : Player(s) {}

	//player's make move
	Board::Move makeMove(const Board& b);
	
};

#endif

