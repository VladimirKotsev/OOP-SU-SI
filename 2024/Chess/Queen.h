#pragma once
#include "Rook.h"
#include "Bishop.h"

class Queen : public Rook, public Bishop
{
public:
	Queen(bool isWhite);

	bool canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const override;
	void print() const override;
};


