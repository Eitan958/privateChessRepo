#pragma once
#include <string>
#include "Board.h"

class King
{
public:
	King(std::string currentSquare);
	~King();
	void setCurrentSquare(std::string newCurrentSquare);
	std::string getCurrentSquare() const;
	int checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard);
	int checkIfWhiteChecked(Board board, std::string moveMade);
	int checkIfBlackChecked(Board board, std::string moveMade);


private:
	std::string _currentSquare;
};
