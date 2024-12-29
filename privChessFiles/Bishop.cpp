#include "Bishop.h"
#include <cmath>

Bishop::Bishop(std::string currentSquare)
{
	_currentSquare = currentSquare.substr(0, 2);
}

Bishop::~Bishop()
{
	_currentSquare = "";
}

void Bishop::setCurrentSquare(std::string newCurrentSquare)
{
	_currentSquare = newCurrentSquare;
}

std::string Bishop::getCurrentSquare() const
{
	return _currentSquare;
}

int Bishop::checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard)
{
	int i = 0;
	int j = 0;
	int errorCode = 0;
	bool isWayBlocked = false;
	std::string square = "";
	square = _currentSquare;
	if (abs(_currentSquare[1] - destSquare[1]) != abs(_currentSquare[0] - destSquare[0]))
	{
		errorCode = 6;
		return errorCode;
	}
	if (_currentSquare[1] < destSquare[1] && _currentSquare[0] < destSquare[0])
	{
		for (i = _currentSquare[1] - 47, j = _currentSquare[0] + 1; i < destSquare[1] - 48 && j < destSquare[0]; i++, j++)
		{
			square[0] = j;
			square[1] = i + 48;
			if (gameBoard.getPieceAtSquare(square) != '#')
			{
				isWayBlocked = true;
				errorCode = 6;
				return errorCode;
			}
		}
	}
	else if (destSquare[1] > _currentSquare[1] && destSquare[0] < _currentSquare[0])
	{
		for (i = _currentSquare[1] - 47, j = _currentSquare[0] - 1; i < destSquare[1] - 48 && j > destSquare[0]; i++, j--)
		{
			square[0] = j;
			square[1] = i + 48;
			if (gameBoard.getPieceAtSquare(square) != '#')
			{
				isWayBlocked = true;
				errorCode = 6;
				return errorCode;
			}
		}
	}
	else if (destSquare[1] < _currentSquare[1] && destSquare[0] < _currentSquare[0])
	{
		for (i = _currentSquare[1] - 49, j = _currentSquare[0] - 1; i > destSquare[1] - 48 && j > destSquare[0]; i++, j--)
		{
			square[0] = j;
			square[0] = i + 48;
			if (gameBoard.getPieceAtSquare(square) != '#')
			{
				isWayBlocked = true;
				errorCode = 6;
				return errorCode;
			}
		}
	}
	else if (destSquare[1] < _currentSquare[1] && destSquare[0] > _currentSquare[0])
	{
		for (i = _currentSquare[1] - 49, j = _currentSquare[0] + 1; i > destSquare[1] - 48 && j < destSquare[0]; i--, j++)
		{
			square[0] = j;
			square[0] = i + 48;
			if (gameBoard.getPieceAtSquare(square) != '#')
			{
				isWayBlocked = true;
				errorCode = 6;
				return errorCode;
			}
		}
	}

	if (_currentSquare == destSquare)
	{
		errorCode = 7;
		return errorCode;
	}
	if ((turn != 0 && pieceAtSquare == 'B') || (turn == 0 && pieceAtSquare == 'b'))
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
