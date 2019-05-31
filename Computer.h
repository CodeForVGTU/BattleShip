#ifndef __Computer__
#define __Computer__

using namespace std;

const int EIL1 = 13;
const int STULP1 = 13;
extern int Board1[EIL1 + 1][STULP1 + 1];

class Computer {
private:
	int x, y;
	int pos_nr;
	char pos;
public:
	Computer();
	~Computer();
	void Update_Coord(int i);
};

#endif // !__Computer__