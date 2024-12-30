#include "Queen.h"

Queen::Queen(std::string currentSquare)
{
	_currentSquare = currentSquare.substr(0, 2);
}

Queen::~Queen()
{
	_currentSquare = "";
}

void Queen::setCurrentSquare(std::string newCurrentSquare)
{
	_currentSquare = newCurrentSquare;
}

std::string Queen::getCurrentSquare() const
{
	return _currentSquare;
}

int Queen::checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard)
{
	int i = 0;
	int j = 0;
	int errorCode = 0;
	bool isWayBlocked = false;
	std::string square = "";
	square = _currentSquare;
	Rook r(_currentSquare);
	Bishop b(_currentSquare);
	if (((destSquare[0] != _currentSquare[0]) && (destSquare[1] != _currentSquare[1]))
	  && abs(_currentSquare[1] - destSquare[1]) != abs(_currentSquare[0] - destSquare[0]))
	{
		errorCode = 6;
		return errorCode;
	}

	r.checkMoveValid(turn, pieceAtSquare, pieceAtDestSquare, destSquare, gameBoard);
	b.checkMoveValid(turn, pieceAtSquare, pieceAtDestSquare, destSquare, gameBoard);
	if (r._isWayBlocked || b._isWayBlocked)
	{
		errorCode = 6;
		return errorCode;
	}
	
	if (_currentSquare == destSquare)
	{
		errorCode = 7;
		return errorCode;
	}
	if ((turn != 0 && pieceAtSquare == 'Q') || (turn == 0 && pieceAtSquare == 'q'))
	{
		errorCode = 2;
		return errorCode;
	}
	if (turn != 0 && (pieceAtDestSquare >= 'a' && pieceAtDestSquare <= 'z')
		|| turn == 0 && (pieceAtDestSquare >= 'A' && pieceAtDestSquare <= 'Z'))
	{
		errorCode = 3;
		return errorCode;
	}
	return errorCode;
}
