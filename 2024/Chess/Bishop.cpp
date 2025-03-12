#include "Bishop.h"

Bishop::Bishop(bool isWhite) : Figure(isWhite, FigureType::BishopFigure)
{
}

bool Bishop::canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const
{
    return abs((int)x - (int)destX) == abs((int)y - (int)destY);
}

void Bishop::print() const
{
	if (getIsWhite())
		std::cout << 'B';
	else
		std::cout << 'b';
}
