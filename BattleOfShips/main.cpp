#include <iostream>
#include "ShipBoard.h"

using namespace std;


int main()
{
	int size = 11;
	//char** classicBoard;
	Board board1;
	Board board2;

	string player1;
	string player2;
	board1.clearBoard();
	try
	{
	board1.placeShips();
	}
	catch (const out_of_range& err)
	{
		cout << err.what() << endl; //wyj¹tek - tak dla zabawy
	}
	board1.printBoard();

	return 0;
}