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
	int surfaceN; // the number of points used to draw the surface of Mars.
	cin >> surfaceN; cin.ignore();
	int lowestY = 3000;

	for (int i = 0; i < surfaceN; i++) {
		int landX; // X coordinate of a surface point. (0 to 6999)
		int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
		cin >> landX >> landY; cin.ignore();
		if (landY < lowestY)
		{
			lowestY = landY;
		}
	}

	int auxPower = 0;

	// game loop
	while (1) {
		int X;
		int Y;
		int hSpeed; // the horizontal speed (in m/s), can be negative.
		int vSpeed; // the vertical speed (in m/s), can be negative.
		int fuel; // the quantity of remaining fuel in liters.
		int rotate; // the rotation angle in degrees (-90 to 90).
		int power; // the thrust power (0 to 4).
		cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();

		// Write an action using cout. DON'T FORGET THE "<< endl"
		// To debug: cerr << "Debug messages..." << endl;

		cerr << vSpeed << endl;
		cerr << Y << endl;
		cerr << lowestY << endl;

		/*Balance the thrust power so the vSpeed is between 35 - 36 to avoid a Collision*/
		if (Y <= lowestY + 2000)
		{
			switch (vSpeed)
			{
			case -35 ... 500:
				cerr << "** -25 -1 ***" << endl;
				if (auxPower > 0)
				{
					auxPower--;
				}
				break;

			case -500 ... - 36:
				cerr << "** -11 -20 ***" << endl;

				if (auxPower < 4)
				{
					auxPower++;
				}
				break;
			}

		}
		else if (vSpeed < -44)
		{
			if (auxPower < 4)
			{
				auxPower++;
			}
		}

		cout << "0" << " " << auxPower << endl; // rotate power. rotate is the desired rotation angle. power is the desired thrust power.
	}
}