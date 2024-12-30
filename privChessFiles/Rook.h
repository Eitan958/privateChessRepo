#pragma once
#include <string>
#include "Board.h"

class Rook
{
public:
	Rook(std::string currentSquare);
	~Rook();
	void setCurrentSquare(std::string newCurrentSquare);
	std::string getCurrentSquare() const;
	int checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard);

	bool _isWayBlocked;
private:
	std::string _currentSquare;
};

