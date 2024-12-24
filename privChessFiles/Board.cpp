#include "Board.h"

Board::Board(std::string board) : _boardString(board)
{
	int row = 0;
	int col = 0;
	int i = 0;
	for (row = 0; row < BOARD_SIZE; row++)
	{
		for (col = 0; col < BOARD_SIZE; col++)
		{
			_board[row][col] = board[i];
			i++;
		}
	}
}

Board::~Board()
{
	int row = 0;
	int col = 0;
	for (row = 0; row < BOARD_SIZE; row++)
	{
		for (col = 0; col < BOARD_SIZE; col++)
		{
			_board[row][col] = 0;
		}
	}
	_boardString = "";
}

void Board::updateBoard(std::string newBoard)
{
	int row = 0;
	int col = 0;
	int i = 0;
	for (row = 0; row < BOARD_SIZE; row++)
	{
		for (col = 0; col < BOARD_SIZE; col++)
		{
			_board[row][col] = newBoard[i];
			i++;
		}
	}
	_boardString = newBoard;
}

std::string Board::getBoard() const
{
	return _boardString;
}

char Board::getPieceAtSquare(std::string square)
{
	int row = 0;
	int col = 0;
	char pieceAtSquare = '#';



	row = 8 - (square[1] - 48);
	col = square[0] - 97;

	pieceAtSquare = _board[row][col];
	return pieceAtSquare;
}
