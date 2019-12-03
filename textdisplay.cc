#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay()
{
	for (int i = 0; i < height; i++)
	{
		vector<char> row;
		for (int j = 0; j < width; j++) //pushes characters onto the vector
		{
			row.push_back('*');
		}
		board.push_back(row); //pushes the vectors into the board
	}
}
ostream &operator<<(ostream &out, const TextDisplay &td)
{
	for (int i = 0; i < td.height; i++) //outputs each individual cell
	{
		for (int j = 0; j < td.width; j++)
		{
			out << td.board[i][j];
		}
		out << endl;
	}
	return out;
}

void TextDisplay::updateDisplay(Board b, bool blind){
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (b.getGrid()[i][j]->getIsOccupied()){
				board[i][j] = b.getGrid()[i][j]->getBlockType(); //sets each cell to its updated block type
			}
			else {
				board[i][j] = ' '; //sets cell to empty if it is not occupied
			}
		}
	}

	if (blind){
		for (int i = 2; i < 12; i++)
			for (int j = 2; j < 9; j++) board[i][j] = '?'; //sets cells to ? if blind is active
	}
}

vector<vector<char>> TextDisplay::getBoard(){
	return board;
}
