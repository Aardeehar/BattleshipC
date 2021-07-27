/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include <iostream>
#include "Board.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player {

public: 

	Player(const std::string& s); //argumented constructor (no default)

	//return the appropriate name
	inline std::string getName() { return name; }

	virtual Board::Move makeMove(const Board& b) = 0; //pure virtual function
	
private: 
	//name variable
	std::string name = "";

};

#endif