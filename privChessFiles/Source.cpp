/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include <iostream>
#include <thread>

#include "Board.h"
#include "Rook.h"
#include "King.h"
#include "Knight.h"

using std::cout;
using std::endl;
using std::string;


void main()
{
	srand(time_t(NULL));


	Pipe p;
	bool isConnect = p.connect();

	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1"); // just example...
	Board gameBoard("RNBKQBNRPPPPPPPP################################pppppppprnbkqbnr1");


	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	 
	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		int errorType = 0;
		char pieceAtSquare = '#';
		char pieceAtDestSquare = '#';
		string oldMsgFromGraphics = msgFromGraphics;

		pieceAtSquare = gameBoard.getPieceAtSquare(msgFromGraphics);
		pieceAtDestSquare = gameBoard.getPieceAtSquare(msgFromGraphics.substr(2, 4));
		cout << "\n\n\n\n\n" << pieceAtSquare << "\n\n\n\n\n\n";
		if (pieceAtSquare == 'R' || pieceAtSquare == 'r')
		{
			Rook r(msgFromGraphics);
			errorType = r.checkMoveValid(gameBoard._turn, pieceAtSquare, pieceAtDestSquare, msgFromGraphics.substr(2, 4), gameBoard);
		}
		else if (pieceAtSquare == 'N' || pieceAtSquare == 'n')
		{
			Knight n(msgFromGraphics);
			errorType = n.checkMoveValid(gameBoard._turn, pieceAtSquare, pieceAtDestSquare, msgFromGraphics.substr(2, 4), gameBoard);
		}
		else if (pieceAtSquare == 'B')
		{

		}
		else if (pieceAtSquare == 'K')
		{

		}
		else if (pieceAtSquare == 'Q')
		{

		}
		else if (pieceAtSquare == '#')
		{
			errorType = 2;
		}
		// YOUR CODE
		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		//int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(errorType + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
		if (errorType == 0 || errorType == 1)
		{
			gameBoard._turn = !(gameBoard._turn);
			gameBoard.updateBoard(oldMsgFromGraphics);
		}
	}

	p.close();
}