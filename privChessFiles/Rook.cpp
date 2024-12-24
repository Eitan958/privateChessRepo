#include "Rook.h"

Rook::Rook(std::string currentSquare)
{
	_currentSquare = currentSquare[0] + currentSquare[1];
}

Rook::~Rook()
{
	_currentSquare = "";
}

void Rook::setCurrentSquare(std::string newCurrentSquare)
{
	_currentSquare = newCurrentSquare;
}

std::string Rook::getCurrentSquare() const
{
	return _currentSquare;
}

char Rook::checkMoveValid(std::string currentSquare, std::string destSquare, std::string board)
{
	char errorCode = '0';
  // if((destSquare[0] != currentSquare[0]) && (destSquare[1] != currentSquare[1])
	 //|| )
  // {
	 //  errorCode = '6';
	 //  return errorCode;
  // }
	return errorCode;
}
