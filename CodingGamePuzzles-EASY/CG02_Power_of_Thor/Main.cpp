#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
* ---
* Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
**/
int main()
{
	int lightX; // the X position of the light of power
	int lightY; // the Y position of the light of power
	int initialTX; // Thor's starting X position
	int initialTY; // Thor's starting Y position
	cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();

	// game loop
	while (1) {
		int remainingTurns;
		cin >> remainingTurns; cin.ignore();
		string direction = "";
		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;

		//It's always better to move in diagonal (if possible)
		//So, first decide if target is at south or north of currentPos
		if (initialTY < lightY)
		{
			direction = "S";
			initialTY++;
		}
		else if (initialTY > lightY)
		{
			direction = "N";
			initialTY--;
		}

		//Then decide the angle: left or right or any of them in case is a straight line
		if (initialTX < lightX)
		{
			direction += "E";
			initialTX++;
		}
		else if (initialTX > lightX)
		{
			direction += "W";
			initialTX--;
		}
		
		cout << direction << endl; // A single line providing the move to be made: N NE E SE S SW W or NW
	}
}