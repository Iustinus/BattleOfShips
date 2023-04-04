#ifndef SHIPBOARD_H
#define SHIPBOARD_H
#include <iostream>
#include <string>

using namespace std;

class Board
{
	
	
public:

	Board();	
	bool isFinished();
	bool isComplete();
	bool isBusy(string input);
	bool checkRight(int row, int col, int shipType);
	bool checkLeft(string input);
	bool checkCorectness(string input);
	void placeShips();
	void clearBoard();
	void printBoard();
	//void calculatePosition(string input);
	void calcPlaceShip(string input, int shipType);
	void placeSingleShip(int shipType, int row, int col, char direction);


private:
	
	const int MAX_SIZE = 11;
	string input;
	char myBoardPtr[11][11];
	int size =0;
	int shipType =0;
	int rowToPlace =0;
	int colToPlace =0;

};


#endif
