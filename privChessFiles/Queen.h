#pragma once
#include <string>
#include "Board.h"
#include "Rook.h"
#include "Bishop.h"

class Queen
{
public:
	Queen(std::string currentSquare);
	~Queen();
	void setCurrentSquare(std::string newCurrentSquare);
	std::string getCurrentSquare() const;
	int checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard);


private:
	std::string _currentSquare;
};

