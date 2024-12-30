#include "King.h"

King::King(std::string currentSquare)
{
	_currentSquare = currentSquare.substr(0, 2);
}

King::~King()
{
	_currentSquare = "";
}

void King::setCurrentSquare(std::string newCurrentSquare)
{
	_currentSquare = newCurrentSquare;
}

std::string King::getCurrentSquare() const
{
	return _currentSquare;
}

int King::checkMoveValid(int turn, char pieceAtSquare, char pieceAtDestSquare, std::string destSquare, Board gameBoard)
{
	int i = 0;
	int j = 0;
	int errorCode = 0;
	std::string square = "aa";
	square[0] = _currentSquare[0] - 1;
	square[1] = _currentSquare[1] + 1;
	std::string possibleSquare1 = square;
	square[0] = _currentSquare[0];
	std::string possibleSquare2 = square;
	square[0] = _currentSquare[0] + 1;
	std::string possibleSquare3 = square;
	square[0] = _currentSquare[0] - 1;
	square[1] = _currentSquare[1];
	std::string possibleSquare4 = square;
	square[0] = _currentSquare[0] + 1;
	std::string possibleSquare5 = square;
	square[0] = _currentSquare[0] - 1;
	square[1] = _currentSquare[1] - 1;
	std::string possibleSquare6 = square;
	square[0] = _currentSquare[0];
	std::string possibleSquare7 = square;
	square[0] = _currentSquare[0] + 1;
	std::string possibleSquare8 = square;

	if (destSquare != possibleSquare1 && destSquare != possibleSquare2 && destSquare != possibleSquare3
	 && destSquare != possibleSquare4 && destSquare != possibleSquare5 && destSquare != possibleSquare6
	 && destSquare != possibleSquare7 && destSquare != possibleSquare8)
	{
		errorCode = 6;
		return errorCode;
	}


	if (_currentSquare == destSquare)
	{
		errorCode = 7;
		return errorCode;
	}
	if ((turn != 0 && pieceAtSquare == 'K') || (turn == 0 && pieceAtSquare == 'k'))
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

int King::checkIfWhiteChecked(Board board, std::string moveMade)
{
	int isChecked = 0;
	int row = 0;
	int col = 0;
	int i = 0;
	int j = 0;
	int kingRow = 0;
	int kingCol = 0;
	std::string square = "aa";
	std::string square2 = "aa";
	std::string whiteKSquare = "aa";
	board.updateBoard(moveMade);


	for (row = 0; row < BOARD_SIZE; row++)
	{
		for (col = 0; col < BOARD_SIZE; col++)
		{
			if (board._board[row][col] == 'K')
			{
				kingRow = row;
				kingCol = col;
			}
		}
	}
	whiteKSquare[0] = kingCol + 97;
	whiteKSquare[1] = 8 - kingRow + 48;

	//check if knight checks
	square[0] = whiteKSquare[0] + 1;
	square[1] = whiteKSquare[1] + 2;
	std::string possibleSquare1 = square;
	square[1] = whiteKSquare[1] - 2;
	std::string possibleSquare2 = square;
	square[0] = whiteKSquare[0] - 1;
	std::string possibleSquare3 = square;
	square[1] = whiteKSquare[1] + 2;
	std::string possibleSquare4 = square;
	square[0] = whiteKSquare[0] + 2;
	square[1] = whiteKSquare[1] + 1;
	std::string possibleSquare5 = square;
	square[1] = whiteKSquare[1] - 1;
	std::string possibleSquare6 = square;
	square[0] = whiteKSquare[0] - 2;
	std::string possibleSquare7 = square;
	square[1] = whiteKSquare[1] + 1;
	std::string possibleSquare8 = square;

	if (board.getPieceAtSquare(possibleSquare1) == 'n' || board.getPieceAtSquare(possibleSquare2) == 'n' || board.getPieceAtSquare(possibleSquare3) == 'n'
		|| board.getPieceAtSquare(possibleSquare4) == 'n' || board.getPieceAtSquare(possibleSquare5) == 'n' || board.getPieceAtSquare(possibleSquare6) == 'n'
		|| board.getPieceAtSquare(possibleSquare7) == 'n' || board.getPieceAtSquare(possibleSquare8) == 'n')
	{
		isChecked = 1;
		return isChecked;
	}


	//check if pawn checks
	square[0] = whiteKSquare[0] - 1;
	square[1] = whiteKSquare[1] - 1;
	square2[0] = whiteKSquare[0] + 1;
	square2[1] = whiteKSquare[1] - 1;
	if (board.getPieceAtSquare(square) == 'p' || board.getPieceAtSquare(square2) == 'p')
	{
		isChecked = 1;
		return isChecked;
	}


	//check if rook or queen checks
	for (i = whiteKSquare[1] - 47; i <= 8; i++)
	{
		square[0] = whiteKSquare[0];
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'r' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'r' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = whiteKSquare[1] - 49; i >= 1; i--)
	{
		square[0] = whiteKSquare[0];
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'r' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'r' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}
	for (i = whiteKSquare[0] + 1; i <= 'h'; i++)
	{
		square[0] = i;
		square[1] = whiteKSquare[1];
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'r' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'r' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}
	for (i = whiteKSquare[0] - 1; i >= 'a'; i--)
	{
		square[0] = i;
		square[1] = whiteKSquare[1];
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'r' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'r' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	//check if king checks
	square[0] = whiteKSquare[0] - 1;
	square[1] = whiteKSquare[1] + 1;
	possibleSquare1 = square;
	square[0] = whiteKSquare[0];
	possibleSquare2 = square;
	square[0] = whiteKSquare[0] + 1;
	possibleSquare3 = square;
	square[0] = whiteKSquare[0] - 1;
	square[1] = whiteKSquare[1];
	possibleSquare4 = square;
	square[0] = whiteKSquare[0] + 1;
	possibleSquare5 = square;
	square[0] = whiteKSquare[0] - 1;
	square[1] = whiteKSquare[1] - 1;
	possibleSquare6 = square;
	square[0] = whiteKSquare[0];
	possibleSquare7 = square;
	square[0] = whiteKSquare[0] + 1;
	possibleSquare8 = square;
	if (board.getPieceAtSquare(possibleSquare1) == 'k' || board.getPieceAtSquare(possibleSquare2) == 'k' || board.getPieceAtSquare(possibleSquare3) == 'k'
		|| board.getPieceAtSquare(possibleSquare4) == 'k' || board.getPieceAtSquare(possibleSquare5) == 'k' || board.getPieceAtSquare(possibleSquare6) == 'k'
		|| board.getPieceAtSquare(possibleSquare7) == 'k' || board.getPieceAtSquare(possibleSquare8) == 'k')
	{
		isChecked = 1;
		return isChecked;
	}

	//check if bishop or queen checks
	for (i = whiteKSquare[1] - 47, j = whiteKSquare[0] + 1; i <= 8 && j <= 'h'; i++, j++)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'b' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'b' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = whiteKSquare[1] - 47, j = whiteKSquare[0] - 1; i <= 8 && j >= 'a'; i++, j--)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'b' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'b' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = whiteKSquare[1] - 49, j = whiteKSquare[0] - 1; i >= 1 && j >= 'a'; i--, j--)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'b' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'b' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = whiteKSquare[1] - 49, j = whiteKSquare[0] + 1; i >= 1 && j <= 'h'; i--, j++)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'b' && board.getPieceAtSquare(square) != 'q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'b' || board.getPieceAtSquare(square) == 'q')
		{
			isChecked = 1;
			return isChecked;
		}
	}


	return isChecked;
}

int King::checkIfBlackChecked(Board board, std::string moveMade)
{
	int isChecked = 0;
	int row = 0;
	int col = 0;
	int i = 0;
	int j = 0;
	int kingRow = 0;
	int kingCol = 0;
	std::string square = "aa";
	std::string square2 = "aa";
	std::string blackKSquare = "aa";
	board.updateBoard(moveMade);


	for (row = 0; row < BOARD_SIZE; row++)
	{
		for (col = 0; col < BOARD_SIZE; col++)
		{
			if (board._board[row][col] == 'k')
			{
				kingRow = row;
				kingCol = col;
			}
		}
	}
	blackKSquare[0] = kingCol + 97;
	blackKSquare[1] = 8 - kingRow + 48;

	//check if knight checks
	square[0] = blackKSquare[0] + 1;
	square[1] = blackKSquare[1] + 2;
	std::string possibleSquare1 = square;
	square[1] = blackKSquare[1] - 2;
	std::string possibleSquare2 = square;
	square[0] = blackKSquare[0] - 1;
	std::string possibleSquare3 = square;
	square[1] = blackKSquare[1] + 2;
	std::string possibleSquare4 = square;
	square[0] = blackKSquare[0] + 2;
	square[1] = blackKSquare[1] + 1;
	std::string possibleSquare5 = square;
	square[1] = blackKSquare[1] - 1;
	std::string possibleSquare6 = square;
	square[0] = blackKSquare[0] - 2;
	std::string possibleSquare7 = square;
	square[1] = blackKSquare[1] + 1;
	std::string possibleSquare8 = square;

	if (board.getPieceAtSquare(possibleSquare1) == 'N' || board.getPieceAtSquare(possibleSquare2) == 'N' || board.getPieceAtSquare(possibleSquare3) == 'N'
		|| board.getPieceAtSquare(possibleSquare4) == 'N' || board.getPieceAtSquare(possibleSquare5) == 'N' || board.getPieceAtSquare(possibleSquare6) == 'N'
		|| board.getPieceAtSquare(possibleSquare7) == 'N' || board.getPieceAtSquare(possibleSquare8) == 'N')
	{
		isChecked = 1;
		return isChecked;
	}


	//check if pawn checks
	square[0] = blackKSquare[0] - 1;
	square[1] = blackKSquare[1] + 1;
	square2[0] = blackKSquare[0] + 1;
	square2[1] = blackKSquare[1] + 1;
	if (board.getPieceAtSquare(square) == 'P' || board.getPieceAtSquare(square2) == 'P')
	{
		isChecked = 1;
		return isChecked;
	}


	//check if rook or queen checks
	for (i = blackKSquare[1] - 47; i <= 8; i++)
	{
		square[0] = blackKSquare[0];
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'R' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'R' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = blackKSquare[1] - 49; i >= 1; i--)
	{
		square[0] = blackKSquare[0];
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'R' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'R' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}
	for (i = blackKSquare[0] + 1; i <= 'h'; i++)
	{
		square[0] = i;
		square[1] = blackKSquare[1];
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'R' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'R' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}
	for (i = blackKSquare[0] - 1; i >= 'a'; i--)
	{
		square[0] = i;
		square[1] = blackKSquare[1];
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'R' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'R' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	//check if king checks
	square[0] = blackKSquare[0] - 1;
	square[1] = blackKSquare[1] + 1;
	possibleSquare1 = square;
	square[0] = blackKSquare[0];
	possibleSquare2 = square;
	square[0] = blackKSquare[0] + 1;
	possibleSquare3 = square;
	square[0] = blackKSquare[0] - 1;
	square[1] = blackKSquare[1];
	possibleSquare4 = square;
	square[0] = blackKSquare[0] + 1;
	possibleSquare5 = square;
	square[0] = blackKSquare[0] - 1;
	square[1] = blackKSquare[1] - 1;
	possibleSquare6 = square;
	square[0] = blackKSquare[0];
	possibleSquare7 = square;
	square[0] = blackKSquare[0] + 1;
	possibleSquare8 = square;
	if (board.getPieceAtSquare(possibleSquare1) == 'K' || board.getPieceAtSquare(possibleSquare2) == 'K' || board.getPieceAtSquare(possibleSquare3) == 'K'
		|| board.getPieceAtSquare(possibleSquare4) == 'K' || board.getPieceAtSquare(possibleSquare5) == 'K' || board.getPieceAtSquare(possibleSquare6) == 'K'
		|| board.getPieceAtSquare(possibleSquare7) == 'K' || board.getPieceAtSquare(possibleSquare8) == 'K')
	{
		isChecked = 1;
		return isChecked;
	}

	//check if bishop or queen checks
	for (i = blackKSquare[1] - 47, j = blackKSquare[0] + 1; i <= 8 && j <= 'h'; i++, j++)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'B' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'B' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = blackKSquare[1] - 47, j = blackKSquare[0] - 1; i <= 8 && j >= 'a'; i++, j--)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'B' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'B' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = blackKSquare[1] - 49, j = blackKSquare[0] - 1; i >= 1 && j >= 'a'; i--, j--)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'B' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'B' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}

	for (i = blackKSquare[1] - 49, j = blackKSquare[0] + 1; i >= 1 && j <= 'h'; i--, j++)
	{
		square[0] = j;
		square[1] = i + 48;
		if (board.getPieceAtSquare(square) != '#' && board.getPieceAtSquare(square) != 'B' && board.getPieceAtSquare(square) != 'Q')
		{
			break;
		}
		if (board.getPieceAtSquare(square) == 'B' || board.getPieceAtSquare(square) == 'Q')
		{
			isChecked = 1;
			return isChecked;
		}
	}


	return isChecked;
}
