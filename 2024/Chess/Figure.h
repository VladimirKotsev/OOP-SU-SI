#pragma once
#include <iostream>
#include "Enums.h"

class Figure
{
private:

	FigureType type;
	bool isWhite;

public:
	Figure(bool isWhite, FigureType type);

	virtual bool canBeMoved(size_t x, size_t y, size_t destX, size_t destY) const = 0;
	virtual void print() const = 0;

	FigureType getType() const;
	bool getIsWhite() const;
};

