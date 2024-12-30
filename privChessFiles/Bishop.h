#pragma once
#include "board.h"

class Bishop
{
public:
	Bishop(std::string currentSquare);
	~Bishop();
	void setCurrentSquare(std::string newCurrentSquare);
	std::string getCurrentSquare() const;
	int checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard);

	bool _isWayBlocked;
private:
	std::string _currentSquare;
};
