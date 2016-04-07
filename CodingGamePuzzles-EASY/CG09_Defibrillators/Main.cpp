#define _USE_MATH_DEFINES

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/

const char PROPERTIES_SIZE = 6;
const char delimiters = ';';

// 6371 corresponds to the radius of the earth in km.
const short EARTH_RADIUS = 6371;


double CalculateDistance(double longA, double latA, double longB, double latB);

int main()
{
	double fLON;
	double fLAT;

	string LON;
	cin >> LON; cin.ignore();

	//Check if exists ',', to avoid runtime errors
	if (LON.find_first_of(',', 0) != string::npos)
	{
		//Replace ',' -> '.'
		LON.replace(LON.find_first_of(',', 0), 1, ".");
	}
	//parse string to double
	fLON = atof(LON.c_str());
	//convert degrees to radians
	fLON = fLON * M_PI / 180;

	string LAT;
	cin >> LAT; cin.ignore();
	if (LAT.find_first_of(',', 0) != string::npos)
	{
		LAT.replace(LAT.find_first_of(',', 0), 1, ".");
	}
	fLAT = atof(LAT.c_str());
	fLAT = fLAT * M_PI / 180;

	cerr << fLON << " " << fLAT << endl;

	int N;
	cin >> N; cin.ignore();

	string answer;
	string currentName;

	double fCurrLON;
	double fCurrLAT;
	double xValue;
	double yValue;
	double distance;
	double minDistance = INFINITY;
	//Used to replace ',' -> '.' on LAT and LON
	string aux;

	for (int i = 0; i < N; i++)
	{
		string DEFIB;
		getline(cin, DEFIB);

		size_t current;
		//Start after the first ';', no need to obtain the first line value
		size_t next = -1;
		for (char j = 0; j < PROPERTIES_SIZE; j++)
		{
			current = next + 1;
			next = DEFIB.find_first_of(delimiters, current);
			switch (j)
			{
				//Name of the defib
			case 1:
				currentName = DEFIB.substr(current, next - current);
				break;
				//LON
			case 4:
				aux = DEFIB.substr(current, next - current);
				if (aux.find_first_of(',', 0) != string::npos)
				{
					aux.replace(aux.find_first_of(',', 0), 1, ".");
				}
				fCurrLON = atof(aux.c_str());
				fCurrLON = fCurrLON * M_PI / 180;
				break;
				//LAT
			case 5:
				aux = DEFIB.substr(current, next - current);
				if (aux.find_first_of(',', 0) != string::npos)
				{
					aux.replace(aux.find_first_of(',', 0), 1, ".");
				}
				fCurrLAT = atof(aux.c_str());
				fCurrLAT = fCurrLAT * M_PI / 180;

				break;
			}
		}

		cerr << currentName << " " << fCurrLON << " " << fCurrLAT << endl;

		distance = CalculateDistance(fLON, fLAT, fCurrLON, fCurrLAT);

		cerr << minDistance << " " << distance << endl;

		if (distance < minDistance)
		{
			minDistance = distance;
			answer = currentName;
		}

		cerr << "------" << endl;
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	cout << answer << endl;
}

/* Returns the distance between a point A and a point B using latitutes*/
double CalculateDistance(double longA, double latA, double longB, double latB) {
	double x = (longB - longA)*cos((latA + latB) / 2);
	double y = latB - latA;
	return (sqrt(x*x + y*y) * EARTH_RADIUS);
}