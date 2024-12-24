#pragma once
#include <string>
class Rook
{
public:
	Rook(std::string currentSquare);
	~Rook();
	void setCurrentSquare(std::string newCurrentSquare);
	std::string getCurrentSquare() const;
	char checkMoveValid(std::string currentSquare, std::string destSquare, std::string board);


private:
	std::string _currentSquare;
};

