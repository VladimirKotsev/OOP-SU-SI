#include "Rook.h"

Rook::Rook(bool isWhite) : Figure(isWhite, FigureType::RookFigure)
{
}

bool Rook::canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const
{
    return false;
}

void Rook::print() const
{
}
