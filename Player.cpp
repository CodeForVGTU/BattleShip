#include "Player.h"
#include <iostream>
#include <String>

using namespace std;

int Board[EIL + 1][STULP + 1] = { 0 };

Player::Player()
{
	Cord = "";
	pos = ' ';
	x = 0;
	y = 0;
}
Player::Player(int a, int b, string c, char d)
{
	x = a;
	y = b;
	Cord = c;
	pos = d;
}
Player::~Player() {} //Destructor

void Player::Draw_Board()
{
	cout << "                   Player\n            0 1 2 3 4 5 6 7 8 9\n";
	char letter = 'A';

	for (int i = 1; i < EIL - 1; i++) {
		cout << "          " << letter++ << " ";
		for (int j = 1; j < STULP - 1; j++) {

			if (Board[i][j] == 0 || Board[i][j] == 2) // 0 for free Coordinate; 2 for Ship sides
				cout << ". ";
			else if (Board[i][j] == 1) // 1 for SHIP
				cout << "0 ";
		}
		cout << endl;
	}
}
void Player::Input_Coord()
{
	bool correct_cord;

	do {
		cout << "   Input a coordinates X & Y (Ex.: A5): ";
		cin >> Cord;

		//Assci Table
		x = Cord[0] - 64; // Char Letter to our needed number 
		y = Cord[1] - 47; // Char number to our needed number

		// Checking if input is correct
		correct_cord = false;

		if (Cord.size() == 2) { // Correct number of symbols - 2
			for (char i = 'A'; i <= 'J'; i++) {
				if (Cord[0] == i) { //Checking if FIRST entered symbol is equal to a letter coordinate
					correct_cord = true;
					break;
				}
			}

			if (!(isdigit(Cord[1]))) { //Checking if SECOND entered symbol is a digit
				correct_cord = false; // It will be false if symbol isn't a digit
			}
		}
	} while (!(correct_cord));
}
void Player::Input_Pos()
{
	do {
		cout << "   Enter position H/V: ";
		cin >> pos;

		if ((pos == 'V') || (pos == 'H')) break;
	} while (true);
}
void Player::Update_Coord(int i)
{
	bool repeat_input = false;
	
	while (true) {
		if (Board[x][y] == 0) { // checking if first coordinate is free for ship

			if (i > 6)  Board[x][y] = 1; // It puts 1 size ships here
			break;
		}
		else { //Else for ship coordinates collision
			Input_Coord();
			if (i < 7) Input_Pos(); // Position is needed UNTIL 7th ship
		}
	}

	if (i < 7)
		while (true) { // It will stop if it's okay to put ship into board
			if (pos == 'V') { // VERTICAL POSITION **************************************************************
				if (i == 1) {
					if (x  < 8) { // Ship wouldn't pass a bottom border
						if (Board[x+1][y] == 0 && Board[x+2][y] == 0 && Board[x+3][y] == 0) { //Checking if 4 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x+1][y] = 1;
							Board[x+2][y] = 1;
							Board[x+3][y] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {//ship passes a border
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4) {
					if (x < 9) { // Ship wouldn't pass a bottom border
						if (Board[x+1][y] == 0 && Board[x+2][y] == 0) { //Checking if 3 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x+1][y] = 1;
							Board[x+2][y] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7) {
					if (x < 10) { // Ship wouldn't pass a bottom border
						if (Board[x+1][y] == 0) { //Checking if 2 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x+1][y] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
			}
			else if (pos == 'H') { // HORIZONTAL POSITION **************************************************************
				if (i == 1) {
					if (y < 8) { // Ship wouldn't pass a RIGHT border
						if (Board[x][y+1] == 0 && Board[x][y+2] == 0 && Board[x][y+3] == 0) { //Checking if 4 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x][y+1] = 1;
							Board[x][y+2] = 1;
							Board[x][y+3] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else { //ship passes a border
						repeat_input = true;
					}
				}
				else if (i >= 2 && i < 4) {
					if (y < 9) { // Ship wouldn't pass a RIGHT border
						if (Board[x][y+1] == 0 && Board[x][y+2] == 0) { //Checking if 3 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x][y+1] = 1;
							Board[x][y+2] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
				else if (i > 3 && i < 7) {
					if (y < 10) { // Ship wouldn't pass a RIGHT border
						if (Board[x][y+1] == 0) { //Checking if 2 long ship coordinates are free for ship
							Board[x][y] = 1;
							Board[x][y+1] = 1;
							break;
						}
						else {
							repeat_input = true;
						}
					}
					else {
						repeat_input = true;
					}
				}
			}

			if (repeat_input) {
				Input_Coord();
				if (i < 7) Input_Pos(); // Position is needed UNTIL 7th ship
			}
		}
	// Area around the ship
	for (int p = 0; p < 4; p++) {

		if (Board[x + 1][y] == 0) Board[x + 1][y] = 2;
		if (Board[x][y + 1] == 0) Board[x][y + 1] = 2;
		if (Board[x - 1][y] == 0) Board[x - 1][y] = 2;
		if (Board[x][y - 1] == 0) Board[x][y - 1] = 2;
		if (Board[x + 1][y + 1] == 0) Board[x + 1][y + 1] = 2;
		if (Board[x - 1][y - 1] == 0) Board[x - 1][y - 1] = 2;
		if (Board[x + 1][y - 1] == 0) Board[x + 1][y - 1] = 2;
		if (Board[x - 1][y + 1] == 0) Board[x - 1][y + 1] = 2;

		if (Board[x + 1][y] == 1) x++;
		if (Board[x][y + 1] == 1) y++;
	}
}