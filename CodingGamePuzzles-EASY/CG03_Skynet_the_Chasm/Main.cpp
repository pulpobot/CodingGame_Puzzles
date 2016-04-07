#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int road; // the length of the road before the gap.
	cin >> road; cin.ignore();
	int gap; // the length of the gap.
	cin >> gap; cin.ignore();
	int platform; // the length of the landing platform.
	cin >> platform; cin.ignore();

	// game loop
	while (1)
	{
		int speed; // the motorbike's speed.
		cin >> speed; cin.ignore();
		int coordX; // the position on the road of the motorbike.
		cin >> coordX; cin.ignore();

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;

		cerr << "Coord: " << coordX << endl;
		cerr << "Road: " << road << endl;
		cerr << "Gap: " << gap << endl;

		/*
			Mainly 5 decisions to take in the next priority order:
			- Slow if the the bike has already passed the gap
			- Jump if the speed is enough to jump the gap and the road missing to reach the gap

			- Speed up till the bike reaches just about the size of the gap
			- or Slow down if the bike's speed is higher than the gap's size
			- or just WAIT if the bike has the right speed to jump
		*/
		cerr << "Calc: " << (road - coordX) + gap << endl;

		if (coordX >= (gap + road))
		{
			cout << "SLOW" << endl;
		}
		else if (speed >= ((road - coordX) + gap))
		{
			cout << "JUMP" << endl;
		}
		else if (coordX <= (road - 1))
		{
			if (speed < (gap + 1))
			{
				cout << "SPEED" << endl;
			}
			else if (speed >(gap + 1))
			{
				cout << "SLOW" << endl;   
			}
			else
			{
				cout << "WAIT" << endl;
			}
		}

	}
}