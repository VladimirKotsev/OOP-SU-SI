#include "King.h"

King::King(bool isWhite) : Figure(isWhite, FigureType::KingFigure)
{

}

bool King::canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const
{
    return false;
}

void King::print() const
{
	if (getIsWhite())
		std::cout << 'K';
	else
		std::cout << 'k';
}
