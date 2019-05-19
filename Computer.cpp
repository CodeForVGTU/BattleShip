#include "Computer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime> // time for random

using namespace std;

int Board1[EIL1+1][STULP1+1] = { 0 };

Computer::Computer()
{
	srand((unsigned int)time(NULL)); // random time to generate random number EVERYTIME
	pos = ' ';
	x = 1 + (rand() % 10);
	y = 1 + (rand() % 10);
	pos_nr = rand() % 2;

	switch (pos_nr)
	{
	case 0: pos = 'H';
		break;
	case 1: pos = 'V';
		break;
	}
}
Computer::~Computer() {}

void Computer::Update_Coord(int i)
{
	bool repeat_input = false;

	while (true) {
		if (Board1[x][y] == 0) { // checking if first coordinate is free for ship

			if (i > 6) Board1[x][y] = 1; // It puts 1 size ships here
			break;
		}
		else { //Else for ship coordinates collision
			srand((unsigned int)time(NULL)); // random time to generate random number EVERYTIME

			x = 1 + (rand() % 10);
			y = 1 + (rand() % 10);

			if (i < 7) { // Position is needed UNTIL 7th ship
				pos_nr = rand() % 2;

				switch (pos_nr)
				{
				case 0: pos = 'H';
					break;
				case 1: pos = 'V';
					break;
				}
			}

		}
	}

		if (i < 7) {
			while (true) { // It will stop if it's okay to put ship into board
				if (pos == 'V') { // VERTICAL POSITION **************************************************************
					if (i == 1) {
						if (x < 8) { // Ship wouldn't pass a bottom border
							if (Board1[x + 1][y] == 0 && Board1[x + 2][y] == 0 && Board1[x + 3][y] == 0) { //Checking if 4 long ship coordinates are free for ship
								Board1[x][y] = 1;
								Board1[x + 1][y] = 1;
								Board1[x + 2][y] = 1;
								Board1[x + 3][y] = 1;
								break;
							}
							else {
								repeat_input = true;
							}
						}
						else {// ship passes a border
							repeat_input = true;
						}
					}
					else if (i >= 2 && i < 4) {
						if (x < 9) { // Ship wouldn't pass a bottom border
							if (Board1[x + 1][y] == 0 && Board1[x + 2][y] == 0) { //Checking if 3 long ship coordinates are free for ship
								Board1[x][y] = 1;
								Board1[x + 1][y] = 1;
								Board1[x + 2][y] = 1;
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
							if (Board1[x + 1][y] == 0) { //Checking if 2 long ship coordinates are free for ship
								Board1[x][y] = 1;
								Board1[x + 1][y] = 1;
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
							if (Board1[x][y + 1] == 0 && Board1[x][y + 2] == 0 && Board1[x][y + 3] == 0) { //Checking if 4 long ship coordinates are free for ship
								Board1[x][y] = 1;
								Board1[x][y + 1] = 1;
								Board1[x][y + 2] = 1;
								Board1[x][y + 3] = 1;
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
							if (Board1[x][y + 1] == 0 && Board1[x][y + 2] == 0) { //Checking if 3 long ship coordinates are free for ship
								Board1[x][y] = 1;
								Board1[x][y + 1] = 1;
								Board1[x][y + 2] = 1;
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
							if (Board1[x][y + 1] == 0) { //Checking if 2 long ship coordinates are free for ship
								Board1[x][y] = 1;
								Board1[x][y + 1] = 1;
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
					srand((unsigned int)time(NULL)); // random time to generate random number EVERYTIME

					x = 1 + (rand() % 10);
					y = 1 + (rand() % 10);

					if (i < 7) { // Position is needed UNTIL 7th ship
						pos_nr = rand() % 2;

						switch (pos_nr)
						{
						case 0: pos = 'H';
							break;
						case 1: pos = 'V';
							break;
						}
					}
				}
			}
		}
	for (int p = 0; p < 4; p++) {

		if (Board1[x + 1][y] == 0) Board1[x + 1][y] = 2;
		if (Board1[x][y + 1] == 0) Board1[x][y + 1] = 2;
		if (Board1[x - 1][y] == 0) Board1[x - 1][y] = 2;
		if (Board1[x][y - 1] == 0) Board1[x][y - 1] = 2;
		if (Board1[x + 1][y + 1] == 0) Board1[x + 1][y + 1] = 2;
		if (Board1[x - 1][y - 1] == 0) Board1[x - 1][y - 1] = 2;
		if (Board1[x + 1][y - 1] == 0) Board1[x + 1][y - 1] = 2;
		if (Board1[x - 1][y + 1] == 0) Board1[x - 1][y + 1] = 2;

		if (Board1[x + 1][y] == 1) x++;
		if (Board1[x][y + 1] == 1) y++;
	}
}