#pragma once
#include "Figure.h"

class ChessBoard
{
private:
	struct Cell
	{
		Figure* figure = nullptr;
		Cell() = default;

		Cell(const Cell&) = delete;
		Cell& operator=(const Cell&) = delete;

		bool isEmpty()
		{
			return (figure == nullptr);
		}

		void print() const
		{
			figure->print();
		}

		~Cell()
		{
			delete figure;
		}
	};


	Cell cells[8][8];
public:
	ChessBoard() = default;

	ChessBoard(const ChessBoard&) = delete;
	ChessBoard& operator=(const ChessBoard&) = delete;
	// delete move too

	void print() const;
	void moveFigure(size_t x, size_t y, size_t destX, size_t destY);
};

