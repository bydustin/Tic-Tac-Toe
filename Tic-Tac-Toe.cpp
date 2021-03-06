// ConsoleApplication2.cpp : Defines the entry point for the console application.

#include "stdafx.h"
using namespace std;

void printBoard(char board[3][3]) {
	cout << " -------------" << endl;
	for (int row = 0; row < 3; row++) {
		for (int column = 0; column < 3; column++) {
			cout << " | ";
			cout << board[row][column];
		}
		cout << " | ";
		cout << "\n -------------" << endl;
	}
}

void askInput(int &row, int &column) {
	cout << "Enter which row to place: ";
	cin >> row;
	while (row < 1 || row > 3) {
		cout << "Invalid Input, Try Again" << endl;
		cout << "Enter which row to place: ";
		cin >> row;
	}
	row -= 1;
	cout << "Enter which column to place: ";
	cin >> column;
	while (column < 1 || column > 3) {
		cout << "Invalid Input, Try Again" << endl;
		cout << "Enter which column to place: ";
		cin >> column;
	}
	column -= 1;
}

void switchTurn(int &turn) {
	if (turn == 1)
		turn = 2;
	else
		turn = 1;
}

void printTurn(int turn) {
	if (turn == 1)
		cout << "\nIt's Player 1's Turn! " << endl;
	else
		cout << "\nIt's Player 2's Turn! " << endl;
}

bool isMoveValid(char (&board)[3][3], int row, int column) {
	if (board[row][column] == '-')
		return true;
	else
		return false;
}

void applyMove(int turn, int &totalNumofMoves, char(&board)[3][3],  int row, int column) {
	if (turn == 1)
		board[row][column] = 'X';
	else
		board[row][column] = 'O';
	totalNumofMoves++;
}

bool isGameOver(int turn, int totalNumofMoves, char(&board)[3][3]) {
	char current_turn;
	if (turn == 1)
		current_turn = 'X';
	else
		current_turn = 'O';

	//Check Vertical
	if (board[0][0] == current_turn && board[0][1] == current_turn && board[0][2] == current_turn) {
		cout << "Winner is: " << current_turn << endl;
		return true;
	}
	if (board[1][0] == current_turn && board[1][1] == current_turn && board[1][2] == current_turn) {
		cout << "Winner is: " << current_turn << endl;
		return true;
	}

	if (board[2][0] == current_turn && board[2][1] == current_turn && board[2][2] == current_turn) {
		cout << "Winner is: " << current_turn << endl;
		return true;
	}

	//Check Horizontal
	if (board[0][0] == current_turn && board[1][0] == current_turn && board[2][0] == current_turn) {
		cout << "Winner is: " << current_turn << endl;
		return true;
	}
	if (board[0][1] == current_turn && board[1][1] == current_turn && board[2][1] == current_turn) {
		cout << "Winner is: " << current_turn << endl;
		return true;
	}
	if (board[0][2] == current_turn && board[1][2] == current_turn && board[2][2] == current_turn) {
		cout << "Winner is: " << current_turn << endl;
		return true;
	}
	//Check Diagonals
	if (board[0][0] == current_turn && board[1][1] == current_turn && board[2][2] == current_turn){
		cout << "Winner is: " << current_turn << endl;
		return true;
	}
	if (board[0][2] == current_turn && board[1][1] == current_turn && board[2][0] == current_turn) {
		cout << "Winner is: " << current_turn << endl;
		return true;
	}
	if (totalNumofMoves < 9)
		return false;

	cout << "Game Tie! Game Over!";
	return true;
}

int main() {
	int turn = 1;
	int row, column;
	int totalNumofMoves = 0;
	char board[3][3] = { { '-','-','-' },{ '-','-','-' },{ '-','-','-' } };
	printBoard(board);
	while (1) {
		printTurn(turn);
		askInput(row, column);
		while (!isMoveValid(board, row, column)) {
			cout << "\nLocation is Occupied." << endl;
			askInput(row, column);
		}
		applyMove(turn, totalNumofMoves, board, row, column);
		printBoard(board);
		if (isGameOver(turn, totalNumofMoves, board))
			break;
		switchTurn(turn);
	}
	cin.get();
	cin.get();
	return 0;
}
