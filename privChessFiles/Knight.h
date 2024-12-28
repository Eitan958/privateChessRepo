#pragma once
#include <string>
#include "Board.h"

class Knight
{
public:
	Knight(std::string currentSquare);
	~Knight();
	void setCurrentSquare(std::string newCurrentSquare);
	std::string getCurrentSquare() const;
	int checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard);


private:
	std::string _currentSquare;
};
