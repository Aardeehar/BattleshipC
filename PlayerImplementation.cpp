/*Name: Aarden Muller-Hartle
ID: 0342958
BattleShip
*/
#include "Player.h"
#include <string>

//implementation of class Player

//argumented constructor, takes in the string for the name
Player::Player(const std::string& s) {
	//if the computer enters a name, make it a computer player
	if (s.length() == 1) {
		name = "Computer ";
		name += s;
	}
	else {
		//its a human player
		name = s;
	}
}
