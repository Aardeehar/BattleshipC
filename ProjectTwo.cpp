/*Name: Aarden Muller-Hartle
Program Description: This program uses inheritance to simulate a 
game of BattleShip between two players, either human (user entered)
or Computer (makes random, but legal, moves). 
*/

#include <iostream>
#include "Game.h"


int main()
{
	
	Game g1; //create game object
	g1.selectPlayers(); //select the player type (H for human, C for computer)
	g1.play(); //play the game!
	g1.announceWinner(); //announce who wins

	return 0; 

}

