#include "Knight.h"

Knight::Knight(bool isWhite) : Figure(isWhite, FigureType::KnightFigure)
{
}

bool Knight::canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const
{
	int xMov?ment[] = { 1, 1, -1, -1, 2, -2, 2, -2 };
	int yMov?ment[] = { 2, -2, 2, -2, 1, 1, -1, -1 };

	for (int i = 0; i < 8; i++)
	{
		if (y + xMov?ment[i] == destX &&
			x + yMov?ment[i] == destY)
			return true;
	}
	return false;
}

void Knight::print() const
{
	if (getIsWhite())
		std::cout << 'K';
	else
		std::cout << 'k';
}
