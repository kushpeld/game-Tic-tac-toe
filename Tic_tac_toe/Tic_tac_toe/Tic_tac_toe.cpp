#include "stdafx.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
using std::tolower;
char board[9] = {}; 
void clrscr() {
	for (int i = 0; i < 10; i++) {
		cout << endl;
	}
}
void clear_board() {
	for (int i = 0; i < 9; i++) {
		board[i] = '-';
	}
}
void print_board(string indent)
{
	cout << endl;
	cout << indent << "\t\t-" << board[6] << "-|-" << board[7] << "-|-" << board[8] << "-" << endl;
	cout << indent << "\t\t-" << board[3] << "-|-" << board[4] << "-|-" << board[5] << "-" << endl;
	cout << indent << "\t\t-" << board[0] << "-|-" << board[1] << "-|-" << board[2] << "-" << endl;

}
int get_move()
{
	cout << "\t\tMove options: \n";
	cout << "\t\t-7-|-8-|-9-" << endl;
	cout << "\t\t-4-|-5-|-6-" << endl;
	cout << "\t\t-1-|-2-|-3-" << endl;
	cout << "\n";
	print_board("");

	cout << "\n Your move: ";

    int move;
	cin >> move;
	while (move < 1 || move > 9  || board[move-1] != '-')
	{
		cout << "Please enter a logal move(1-9): \n";
		cin >> move;
	}
	return move;
}
bool has_won(char player) {
	int wins[][3] = { {0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},
					   {2,5,8},{0,4,8},{2,4,6} };
	for (int i = 0; i < 8; i++) {
		int count = 0;
		for (int j = 0; j < 3; j++) {
			if (board[wins[i][j]] == player)
				count++;
		}
		if(count==3)
		{
			return true;
		}
	}
	return false;
}
char get_winner() 
{
	int turn = 1;
	while (!has_won('X') && !has_won('O'))
	{
		clrscr();
		int move = get_move();
		clrscr();
		if (turn % 2 == 1)
		{
			board[move - 1] = 'X';
			if (has_won('X')) {
				cout << "Congratulations player X! You have won!\n";
				return 'X';
			}
		}
		else
		{
			board[move - 1] = 'O';
			if (has_won('O')) {
				cout << "Congratulations player O! You have won!\n";
				return 'O';
			}
		}
			turn++;
			if (turn == 10) {
				cout << "\t   It is a draw!\n";
				return 'D';
			}
		
	}
}
int main()
{
	string play;
	int x_wins = 0, o_wins = 0, ties = 0;
	cout << "Play game in words ? <y/n> ";
	cin >> play;
	while (play != "y" && play != "n")
	{
		cout << "Please enter a valid play (y/n): ";
		cin >> play;
	}
	  if (play == "n")
	  {
		cout << "\t\t\tThe End" << endl;
	  }
	while (play == "y")
	{	
	    
		cout << "Welcome to tic-tac-toe!\n\n";
		clear_board();
		char winner = get_winner();
		print_board("\t");
		switch (winner)
		{
		case 'X':
			x_wins++;
			break;
		case 'O':
			o_wins++;
			break;
		case 'D':
			ties++;
			break;
		}

		cout << "\n\t*Winner Statistics*\nPlayer X: " << x_wins
			<< ", PLayer O: " << o_wins << " and Ties: " << ties << "\n\n";
		cout << "\nWould you like to play again? (y/n): ";
		cin >> play;
		while (play != "y" && play != "n")
		{
			cout << "Please enter a valid play (y/n): ";
			cin >> play;
		}
		if (play == "n") {
			cout << "\t\t\tThe End" << endl;
		}
		
	}
	system("pause");
	return 0;
}
