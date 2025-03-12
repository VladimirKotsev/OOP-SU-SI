#include "ChessBoard.h"

void ChessBoard::print() const
{
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = 0; j < 8; j++)
		{
			cells[i][j].print();
		}

		std::cout << std::endl;
	}
}
