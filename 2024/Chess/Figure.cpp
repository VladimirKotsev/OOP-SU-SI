#include "Figure.h"

Figure::Figure(bool isWhite, FigureType type) : isWhite(isWhite), type(type)
{
}

FigureType Figure::getType() const
{
	return type;
}

bool Figure::getIsWhite() const
{
	return isWhite;
}
