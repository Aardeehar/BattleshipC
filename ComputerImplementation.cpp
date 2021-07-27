/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include "ComputerPlayer.h"
#include <string>
#include <iostream>

char ComputerPlayer::cVal = 'A';

ComputerPlayer::ComputerPlayer() : Player(std::string(1, cVal)) {
	++cVal;

	if (cVal == '[') { //the [ character comes after Z in the ASCII code
		cVal = 'A'; //reset cVal
	}
}
	/*
	To ensure this reset works correctly, cVal was initially set to Z and this
	constructor was called 2 times to ensure proper lettering. This if statement
	does function as expected to 'loop' cVal through A-Z, inclusive.*/




