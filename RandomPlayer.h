/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include "ComputerPlayer.h"
#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include <random>
#include "time.h"

class RandomPlayer : public ComputerPlayer {

public: 
	
	Board::Move makeMove(const Board& b1);
	//make a random, but legal, move
	

};

#endif