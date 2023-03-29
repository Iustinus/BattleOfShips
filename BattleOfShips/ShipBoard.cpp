#include "ShipBoard.h"

using namespace std;

Board::Board()
{
	//Board init
	this->myBoardPtr[0][0] = ' ';
	this->myBoardPtr[1][0] = '1';
	this->myBoardPtr[2][0] = '2';
	this->myBoardPtr[3][0] = '3';
	this->myBoardPtr[4][0] = '4';
	this->myBoardPtr[5][0] = '5';
	this->myBoardPtr[6][0] = '6';
	this->myBoardPtr[7][0] = '7';
	this->myBoardPtr[8][0] = '8';
	this->myBoardPtr[9][0] = '9';
	this->myBoardPtr[10][0] = '0';

	for (int k = 1; k < 11; k++)
	{
		this->myBoardPtr[0][k] = k + 64; //ASCII
	}
	for (int i = 1; i < 11; i++)
	{
		for (int j = 1; j < 11; j++)
		{
			this->myBoardPtr[i][j] = ' ';
		}
	}
}
bool Board::isFinished()
{
	return false;
}
bool Board::isComplete()
{
	return false;
}
bool Board::isBusy(string input)
{
	return false;
}
bool Board::checkCorectness(string input)
{
	return true;
}
void Board::placeShips()
{
	bool allShipsSet = false;
	string input;
	cout << "Etap ustawiania statkow. Statki zawsze sa podluzne. Ustawiamy w taki sposob:" << endl;
	cout << "4 masztowiec - 1szt" << endl;
	cout << "3 masztowiec - 2szt" << endl;
	cout << "2 masztowiec - 3szt" << endl;
	cout << "1 masztowiec - 4szt" << endl;
	
		while (!allShipsSet)
		{
			int shipType = 0;
			for (int i = 4; i >= 1; i--)
			{
				shipType = 5-i;
				switch (shipType)
				{
				case 1:
					cout << "Podaj poczatkowa pozycje dla 4-masztowca (np.: A6):" << endl;
					getline(cin, input);

					this->calculatePosition(input);

					if (!this->isBusy(input))
					{
						myBoardPtr[rowToPlace][colToPlace] = '4';
						cout << "Podaj kierunek: G(ora), D(ol), L(lewo), P(rawo)";
						getline(cin, input);
						char direction = input[0];
						this->placeSingleShip(4, rowToPlace, colToPlace, direction);
						//allShipsSet = true;
					}
					else
					{
						cout << "Pole juz zajete. Wybierz inne!" << endl;
					}
		
					this->printBoard();
					break;
				case 2:
					for (int i = 0; i < 2; i++)
					{
						cout << "Podaj poczatkowa pozycje dla " << i+1<< ". 3-masztowca (np.: A6):" << endl;
						getline(cin, input);
						this->calculatePosition(input);
						if (!this->isBusy(input))
						{
							myBoardPtr[rowToPlace][colToPlace] = '3';
							cout << "Podaj kierunek: G(ora), D(ol), L(lewo), P(rawo)";
							getline(cin, input);
							char direction = input[0];
							this->placeSingleShip(3, rowToPlace, colToPlace, direction);
							//allShipsSet = true;
						}
						else
						{
							cout << "Pole juz zajete. Wybierz inne!" << endl;
						}
						this->printBoard();
					}					
					break;
				case 3:
					for (int i = 0; i < 3; i++)
					{
						cout << "Podaj poczatkowa pozycje dla " << i + 1 << ". 2-masztowca (np.: A6):" << endl;
						getline(cin, input);
						this->calculatePosition(input);
						if (!this->isBusy(input))
						{
							myBoardPtr[rowToPlace][colToPlace] = '2';
							cout << "Podaj kierunek: G(ora), D(ol), L(lewo), P(rawo)";
							getline(cin, input);
							char direction = input[0];
							this->placeSingleShip(2, rowToPlace, colToPlace, direction);
							//allShipsSet = true;
						}
						else
						{
							cout << "Pole juz zajete. Wybierz inne!" << endl;
						}
						this->printBoard();
					}
					break;
				case 4:
					for (int i = 0; i < 4; i++)
					{
						cout << "Podaj poczatkowa pozycje dla " << i + 1 << ". 1-masztowca (np.: A6):" << endl;
						getline(cin, input);
						this->calculatePosition(input);
						if (!this->isBusy(input))
						{
							myBoardPtr[rowToPlace][colToPlace] = '1';
							cout << "Podaj kierunek: G(ora), D(ol), L(lewo), P(rawo)";
							getline(cin, input);
							char direction = input[0];
							this->placeSingleShip(1, rowToPlace, colToPlace, direction);
							//allShipsSet = true;
						}
						else
						{
							cout << "Pole juz zajete. Wybierz inne!" << endl;
						}
						this->printBoard();
					}
					break;
				default:
					throw out_of_range("Wybierz 1, 2, 3, lub 4 masztowca");
					break;
				
				}
			}
	}
}

void Board::clearBoard()
{
	myBoardPtr[0][0] = ' ';
	myBoardPtr[1][0] = '1';
	myBoardPtr[2][0] = '2';
	myBoardPtr[3][0] = '3';
	myBoardPtr[4][0] = '4';
	myBoardPtr[5][0] = '5';
	myBoardPtr[6][0] = '6';
	myBoardPtr[7][0] = '7';
	myBoardPtr[8][0] = '8';
	myBoardPtr[9][0] = '9';
	myBoardPtr[10][0] = '0';

	for (int k = 1; k < MAX_SIZE; k++)
	{
		myBoardPtr[0][k] = k + 64; //ASCII
	}
	for (int i = 1; i < MAX_SIZE; i++)
	{
		for (int j = 1; j < MAX_SIZE; j++)
		{
			myBoardPtr[i][j] = ' ';
		}
	}

}
void Board::printBoard()
{
	cout << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << "\t";
		for (int j = 0; j < MAX_SIZE; j++)
		{
			cout << myBoardPtr[i][j] << " | ";
		}
		cout << endl;
		cout << "\t-------------------------------------------" << endl;
	}
}
void Board::calculatePosition(string input)
{
	int row = 0;
	int col = 0;
	char index1 = input[0];
	char index2 = input[1];
	for (int k = 1; k < 11; k++)
	{
		if (myBoardPtr[0][k] == index1)
		{
			col = k;
			break;
		}
	}
	for (int j = 1; j < 11; j++)
	{
		if (myBoardPtr[j][0] == index2)
		{
			row = j;
			break;
		}
	}
	this->rowToPlace = row;
	this->colToPlace = col;
}

void Board::placeSingleShip(int shipType, int row, int col, char direction)
{
	char shipSym = static_cast<char>(shipType+48);
	switch (direction)
	{
	case 'g':
	case 'G':
	{
		if ((row - shipType - 1 >= 1))
		{
			for (int p = row; p > row - shipType; p--)
			{
				myBoardPtr[p][col] = shipSym;
			}
		}
	}
	break;
	case 'd':
	case 'D':
	{
		if ((row + shipType - 1 <= 11))
		{
			for (int p = row; p < row + shipType; p++)
			{
				myBoardPtr[p][col] = shipSym;
			}
		}
	}
	break;
	case 'l':
	case 'L':
	{
		if (col - shipType - 1 >= 1)
		{
			for (int p = col; p > col - shipType; p--)
			{
				myBoardPtr[row][p] = shipSym;
			}
		}
	}
	break;
	case 'p':
	case 'P':
	{
		if ((col + shipType - 1 <= 11))
		{
			for (int p = col; p < col + shipType; p++)
			{
				myBoardPtr[row][p] = shipSym;
			}
		}
	}
	default:
		break;
	}
}