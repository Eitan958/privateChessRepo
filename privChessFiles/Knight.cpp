#include "Knight.h"

Knight::Knight(std::string currentSquare)
{
	_currentSquare = currentSquare.substr(0, 2);
}

Knight::~Knight()
{
	_currentSquare = "";
}

void Knight::setCurrentSquare(std::string newCurrentSquare)
{
	_currentSquare = newCurrentSquare;
}

std::string Knight::getCurrentSquare() const
{
	return _currentSquare;
}

int Knight::checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard)
{
	int i = 0;
	int j = 0;
	int errorCode = 0;
	std::string square = "aa";
	square[0] = _currentSquare[0] + 1;
	square[1] = _currentSquare[1] + 2;
	std::string possibleSquare1 = square;
	square[1] = _currentSquare[1] - 2;
	std::string possibleSquare2 = square;
	square[0] = _currentSquare[0] - 1;
	std::string possibleSquare3 = square;
	square[1] = _currentSquare[1] + 2;
	std::string possibleSquare4 = square;
	square[0] = _currentSquare[0] + 2;
	square[1] = _currentSquare[1] + 1;
	std::string possibleSquare5 = square;
	square[1] = _currentSquare[1] - 1;
	std::string possibleSquare6 = square;
	square[0] = _currentSquare[0] - 2;
	std::string possibleSquare7 = square;
	square[1] = _currentSquare[1] + 1;
	std::string possibleSquare8 = square;

	if (destSquare != possibleSquare1 && destSquare != possibleSquare2 && destSquare != possibleSquare3 && destSquare != possibleSquare4 && destSquare != possibleSquare5 && destSquare != possibleSquare6 && destSquare != possibleSquare7 && destSquare != possibleSquare8)
	{
		errorCode = 6;
		return errorCode;
	}


	if (_currentSquare == destSquare)
	{
		errorCode = 7;
		return errorCode;
	}
	if ((turn != 0 && pieceAtSquare == 'N') || (turn == 0 && pieceAtSquare == 'n'))
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
