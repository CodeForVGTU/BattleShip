#include <String>

#ifndef __PLAYER__
#define __PLAYER__

using namespace std;

const int EIL = 12;
const int STULP = 12;
extern int Board[EIL + 1][STULP + 1];

class Player {
private:
	int x, y;
	string Cord;
	char pos;
public:
	Player();
	Player(int a, int b, string c, char d);
	~Player();

	void Draw_Board();
	void Input_Coord();
	void Input_Pos();
	void Update_Coord(int i);
};

#endif // !__Player__