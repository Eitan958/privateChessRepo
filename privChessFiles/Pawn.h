#pragma once
#include <string>
#include "Board.h"

class Pawn
{
public:
	Pawn(std::string currentSquare);
	~Pawn();
	void setCurrentSquare(std::string newCurrentSquare);
	std::string getCurrentSquare() const;
	int checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard);


private:
	std::string _currentSquare;
};

