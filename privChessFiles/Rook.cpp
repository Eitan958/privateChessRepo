#include "Rook.h"

Rook::Rook(std::string currentSquare)
{
	_currentSquare = currentSquare.substr(0, 2);
	_isWayBlocked = false;
}

Rook::~Rook()
{
	_currentSquare = "";
	_isWayBlocked = false;
}

void Rook::setCurrentSquare(std::string newCurrentSquare)
{
	_currentSquare = newCurrentSquare;
}

std::string Rook::getCurrentSquare() const
{
	return _currentSquare;
}

int Rook::checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard)
{
	int i = 0;
	int j = 0;
	int errorCode = 0;
	bool isWayBlocked = false;
	std::string square = "";
	square = _currentSquare;
	if((destSquare[0] != _currentSquare[0]) && (destSquare[1] != _currentSquare[1]))
	{
		errorCode = 6;
		return errorCode;
    }
	if (destSquare[0] == _currentSquare[0])
	{
		if (_currentSquare[1] < destSquare[1])
		{
			for (i = _currentSquare[1] - 47; i < destSquare[1] - 48; i++)
			{
				square[1] = i + 48;
				if (gameBoard.getPieceAtSquare(square) != '#')
				{
					_isWayBlocked = true;
				}
			}
		}
		else if (_currentSquare[1] > destSquare[1])
		{
			for (i = _currentSquare[1] - 49; i > destSquare[1] - 48; i--)
			{
				square[1] = i + 48;
				if (gameBoard.getPieceAtSquare(square) != '#')
				{
					_isWayBlocked = true;
				}
			}
		}
	}
	if (destSquare[1] == _currentSquare[1])
	{
		if (_currentSquare[0] < destSquare[0])
		{
			for (i = _currentSquare[0] + 1; i < destSquare[0]; i++)
			{
				square[0] = i;
				if (gameBoard.getPieceAtSquare(square) != '#')
				{
					_isWayBlocked = true;
				}
			}
		}
		else if (_currentSquare[0] > destSquare[0])
		{
			for (i = _currentSquare[0] - 1; i > destSquare[0]; i--)
			{
				square[0] = i;
				if (gameBoard.getPieceAtSquare(square) != '#')
				{
					_isWayBlocked = true;
				}
			}
		}
	}
	if (_isWayBlocked)
	{
		errorCode = 6;
		return errorCode;
	}


	if (_currentSquare == destSquare)
	{
		errorCode = 7;
		return errorCode;
	}
	if ((turn != 0 && pieceAtSquare == 'R') || (turn == 0 && pieceAtSquare == 'r'))
	{
		errorCode = 2;
		return errorCode;
	}
	if (turn != 0 && (pieceAtDestSquare >= 'a' && pieceAtDestSquare <= 'z')
	  ||turn == 0 && (pieceAtDestSquare >= 'A' && pieceAtDestSquare <= 'Z'))
	{
		errorCode = 3;
		return errorCode;
	}
	return errorCode;
}
