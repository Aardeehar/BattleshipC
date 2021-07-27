/*Name: Aarden Muller-Hartle
BattleShip
*/
#ifndef BOARD_H
#define BOARD_H

#include <iostream>

class Board {
public:
	//player and board piece enums
	/*I added a Hit enum to PlayerPiece as in the game Battleship the Player
	board is typically also updated if they are hit.*/
	enum class PlayerPiece { AIRCRAFT, BATTLESHIP, CRUISER, SUBMARINE, PATROL, EMPTY, HIT};
	enum class EnemyPiece { HIT, MISS, EMPTY };

	//struct for Move
	typedef struct Move {
	public:
		char charVal = 'a';
		int indexVal = 0;

		Move(char c, int idx) {
			charVal = tolower(c); //always convert char to lowercase, prevents
			//having to constantly check for upper and lowercase characters
			indexVal = idx;

			if (charVal == 'b') {
				indexVal += 10;
			}
			else if (charVal == 'c') {
				indexVal += 20;
			}
			else if (charVal == 'd') {
				indexVal += 30;
			}
			else if (charVal == 'e') {
				indexVal += 40;
			}
			else if (charVal == 'f') {
				indexVal += 50;
			}
			else if (charVal == 'g') {
				indexVal += 60;
			}
			else if (charVal == 'h') {
				indexVal += 70;
			}
			else if (charVal == 'i') {
				indexVal += 80;
			}
			else if (charVal == 'j') {
				indexVal += 90;
			}
			
		} 
	} Move;
 
	Board();
	void reset() noexcept; 
	void display(int player) const noexcept; //no throwing!
	//overloaded ostream operators
	friend std::ostream& operator << (std::ostream& out, PlayerPiece p1);
	friend std::ostream& operator << (std::ostream& out, EnemyPiece e1);
	//make the move
	EnemyPiece& makeMove(const Move &moveOne);
	//check if legal
	bool isLegal(const Move& legalMove) const noexcept; //no throwing!

	//this function was added to hardcode the locations of the ships for both player boards
	void setShips();
	//return the hits for the ships
	inline int getHitCountOne() { return hitCountOne;  }
	inline int getHitCountTwo() { return hitCountTwo;  }

private: 

	PlayerPiece player1[100]; //player1's board
	PlayerPiece player2[100]; //player2's board

	EnemyPiece enemy1[100]; //enemy1's board
	EnemyPiece enemy2[100]; //enemy2's board

	int hitCountOne;
	int hitCountTwo;
	int count;  //player count
};



#endif
