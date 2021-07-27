/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include "Player.h"
#ifndef COMPUTER_PLAYER_H
#define COMPUTER_PLAYER_H

class ComputerPlayer : public Player {

public: 
	ComputerPlayer(); //default constructor

private:
	static char cVal; //the character value of the computer [A-Z]
};

#endif