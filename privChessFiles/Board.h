#pragma once
#include <string>
#define BOARD_SIZE 8
class Board
{
public:
	Board(std::string board);
	~Board();
	void updateBoard(std::string newBoard);
	std::string getBoard() const;
	char getPieceAtSquare(std::string square);





	char _board[BOARD_SIZE][BOARD_SIZE];
	std::string _boardString;

};

