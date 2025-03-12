#pragma once
#include "Figure.h"

class King : public Figure
{
public:
	King(bool isWhite);

	// Inherited via Figure
	bool canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const override;
	void print() const override;
};

