#include "Queen.h"

Queen::Queen(bool isWhite) : Bishop(isWhite), Rook(isWhite), Figure(isWhite, FigureType::QueenFigure)
{
}

bool Queen::canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const
{
	return false;
}

void Queen::print() const
{
	if (getIsWhite())
		std::cout << 'Q';
	else
		std::cout << 'q';
}
