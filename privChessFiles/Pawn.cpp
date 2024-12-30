#include "Pawn.h"

Pawn::Pawn(std::string currentSquare)
{
	_currentSquare = currentSquare.substr(0, 2);
}

Pawn::~Pawn()
{
	_currentSquare = "";
}

void Pawn::setCurrentSquare(std::string newCurrentSquare)
{
	_currentSquare = newCurrentSquare;
}

std::string Pawn::getCurrentSquare() const
{
	return _currentSquare;
}

int Pawn::checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard)
{
	int i = 0;
	int j = 0;
	int errorCode = 0;
	bool isWayBlocked = false;
	std::string possibleSquare1 = "aa";
	possibleSquare1[0] = _currentSquare[0] - 1;
	possibleSquare1[1] = _currentSquare[1] + 1;
	std::string possibleSquare2 = "aa";
	possibleSquare2[0] = _currentSquare[0] + 1;
	possibleSquare2[1] = _currentSquare[1] + 1;
	std::string square = "";
	square = _currentSquare;
	if (turn != 0)
	{
		if (_currentSquare[1] == '2' && destSquare[1] - _currentSquare[1] > 2)
		{
			errorCode = 6;
			return errorCode;
		}
		if (_currentSquare[1] != '2' && destSquare[1] - _currentSquare[1] > 1)
		{
			errorCode = 6;
			return errorCode;
		}
		if (destSquare[1] < _currentSquare[1])
		{
			errorCode = 6;
			return errorCode;
		}


		if (destSquare[0] != _currentSquare[0])
		{
			if (destSquare != possibleSquare1 && destSquare != possibleSquare2)
			{
				errorCode = 6;
				return errorCode;
			}
			if (destSquare == possibleSquare1)
			{
				if (gameBoard.getPieceAtSquare(possibleSquare1) == '#'
				 || (gameBoard.getPieceAtSquare(possibleSquare1) >= 'a' && gameBoard.getPieceAtSquare(possibleSquare1) <= 'z'))
				{
					errorCode = 6;
					return errorCode;
				}
			}
			if (destSquare == possibleSquare2)
			{
				if (gameBoard.getPieceAtSquare(possibleSquare2) == '#'
					|| (gameBoard.getPieceAtSquare(possibleSquare2) >= 'a' && gameBoard.getPieceAtSquare(possibleSquare2) <= 'z'))
				{
					errorCode = 6;
					return errorCode;
				}
			}
		}

	}
	else if (turn == 0)
	{
		if (_currentSquare[1] == '7' && _currentSquare[1] - destSquare[1] > 2)
		{
			errorCode = 6;
			return errorCode;
		}
		if (_currentSquare[1] != '7' && _currentSquare[1] - destSquare[1] > 1)
		{
			errorCode = 6;
			return errorCode;
		}
		if (destSquare[1] > _currentSquare[1])
		{
			errorCode = 6;
			return errorCode;
		}

		possibleSquare1[0] = _currentSquare[0] - 1;
		possibleSquare1[1] = _currentSquare[1] - 1;
		possibleSquare2[0] = _currentSquare[0] + 1;
		possibleSquare2[1] = _currentSquare[1] - 1;
		if (destSquare[0] != _currentSquare[0])
		{
			if (destSquare != possibleSquare1 && destSquare != possibleSquare2)
			{
				errorCode = 6;
				return errorCode;
			}
			if (destSquare == possibleSquare1)
			{
				if (gameBoard.getPieceAtSquare(possibleSquare1) == '#'
					|| (gameBoard.getPieceAtSquare(possibleSquare1) >= 'A' && gameBoard.getPieceAtSquare(possibleSquare1) <= 'Z'))
				{
					errorCode = 6;
					return errorCode;
				}
			}
			if (destSquare == possibleSquare2)
			{
				if (gameBoard.getPieceAtSquare(possibleSquare2) == '#'
					|| (gameBoard.getPieceAtSquare(possibleSquare2) >= 'A' && gameBoard.getPieceAtSquare(possibleSquare2) <= 'Z'))
				{
					errorCode = 6;
					return errorCode;
				}
			}
		}
	}
	



	if (_currentSquare == destSquare)
	{
		errorCode = 7;
		return errorCode;
	}
	if ((turn != 0 && pieceAtSquare == 'P') || (turn == 0 && pieceAtSquare == 'p'))
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
