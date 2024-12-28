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
	_turn = board[64] - 48;
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

void Board::updateBoard(std::string moveMade)
{
	int sourceRow = 0;
	int sourceCol = 0;
	int destRow = 0;
	int destCol = 0;
	char temp = 'a';

	sourceRow = 8 - (moveMade[1] - 48);
	sourceCol = moveMade[0] - 97;
	destRow = 8 - (moveMade[3] - 48);
	destCol = moveMade[2] - 97;
	temp = _board[sourceRow][sourceCol];

	_board[sourceRow][sourceCol] = '#';
	_board[destRow][destCol] = temp;
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
