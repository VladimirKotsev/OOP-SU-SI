#include "Pawn.h"

Pawn::Pawn(bool isWhite) : Figure(isWhite, FigureType::PawnFigure)
{

}

bool Pawn::canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const
{
	return abs((int)x - (int)destX) == abs((int)y - (int)destY);
}

void Pawn::print() const
{
	if (getIsWhite())
		std::cout << 'P';
	else
		std::cout << 'p';
}
