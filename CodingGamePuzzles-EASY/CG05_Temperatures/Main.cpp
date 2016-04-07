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
	int n; // the number of temperatures to analyse
	cin >> n; cin.ignore();
	string temps; // the n temperatures expressed as integers ranging from -273 to 5526
	getline(cin, temps);

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;
	cerr << temps << endl;

	if (n > 0)
	{
		int result = atoi((temps.substr(0, temps.find(" "))).c_str());
		cerr << "Initial Result: " << result << endl;

		for (int i = 1; i< n; i++)
		{
			//Search for the next number
			int aux = atoi((temps.substr(0, temps.find(" "))).c_str());
			cerr << aux << endl;

			//if current absolute value is less than the current previous closest absolute value
			//or 
			//if both are equal but the current is positive -> grab the current as the new closest value
			if ((abs(aux)) < (abs(result)) || ((abs(aux)) == (abs(result)) && aux > 0) )
			{
				result = aux;
			}
			cerr << "Actual Result: " << result << endl;

			//Delete the number from the string
			temps.erase(0, temps.find(" ") + 1);
		}

		cout << result << endl;

	}
	else
	{

		cout << 0 << endl;
	}
}