#include "textdisplay.h"

using namespace std;

TextDisplay::TextDisplay()
{
	for (int i = 0; i < height; i++)
	{
		vector<char> row;
		for (int j = 0; j < width; j++)
		{
			row.push_back('A');
		}
		board.push_back(row);
	}
}
ostream &operator<<(ostream &out, const TextDisplay &td)
{
	for (int i = 0; i < td.height; i++)
	{
		for (int j = 0; j < td.width; j++)
		{
			out << td.board[i][j];
		}
		out << endl;
	}
	return out;
}

void TextDisplay::updateDisplay(Board b){
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (!b.getGrid()[i][j]->getIsOccupied()){
				//board[i][j] = b.getGrid()[i][j]->getBlockType();
			}
		}
	}

}
