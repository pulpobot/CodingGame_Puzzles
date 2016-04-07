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
	string MESSAGE;
	getline(cin, MESSAGE);

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

	/*Grab each char
	transform it into int
	int -> binary
	add binary string to mayor string
	print result
	*/
	//For each char on the MESSAGE
	string mainS = "";
	string binary = "";

	cerr << MESSAGE << endl;
	for (int j = 0; j< MESSAGE.length(); j++)
	{
		//Grab the char and converted into an integer
		int charValue = MESSAGE[j];
		binary = "";
		//Create a temporal binaryString for each char

		//Create a mask for the AND binary operation 
		int mask = 1;

		/*What we have to do is do an AND operation
		these operation grabs a number  in its binary form (C -> 67 -> 1000011)
		and compare each bit with the mask (1), in case is equal the AND operation
		results in an 1 value else on a 0 value
		so
		1000011 (7 bits)
		0000001 (7 bits) (mask = 1)
		-------
		0000001

		in this case every time we recieve a 1 or 0 we transform it into an string
		We need to take into account that the mask haves to increase on each step
		on each for

		meaning that the next step should be
		1000011 (7 bits)
		0000010 (7 bits) (mask = 2)
		-------
		0000010

		1000011 (7 bits)
		0000100 (7 bits) (mask = 4)
		-------
		0000000
		*/

		for (int i = 0; i < 7; i++)
		{
			if ((mask&charValue) >= 1)
				binary = "1" + binary;
			else
				binary = "0" + binary;

			/*
			We increase the mask by doing a "Left Shift Assignment",
			this moves all the bits one cell to the left
			*/
			mask <<= 1;
		}


		/*
		now that we have the binary string for the char
		lets added to the main string
		*/
		mainS += binary;
	}

	cerr << mainS << endl;

	/*
	Now for each char of the mainS that contains all the binary
	we need to code it in to the Chuck Norris method
	*/
	string answer = "";
	int i = 0;
	while (i<mainS.length())
	{
		if (mainS[i] == '1')
		{
			//Add the first block indicator for the 1s
			answer += "0 0";
			//go to the next char until its diferrent from 1
			cerr << "Pos:" << i << endl;
			cerr << "Char:" << mainS[i] << endl;
			i++;
			cerr << "Pos:" << i << endl;
			cerr << "Char:" << mainS[i] << endl;
			while (mainS[i] == '1' && i<mainS.length())
			{
				answer += "0";
				i++;
			}

			if (i<mainS.length())
			{
				answer += " ";
			}

		}
		else
		{
			//Add the first block indicator for the 0s
			answer += "00 0";
			//go to the next char until its diferrent from 0
			cerr << "Pos:" << i << endl;
			cerr << "Char:" << mainS[i] << endl;
			i++;
			cerr << "Pos:" << i << endl;
			cerr << "Char:" << mainS[i] << endl;
			while (mainS[i] == '0' && i<mainS.length())
			{
				answer += "0";
				i++;
			}

			if (i<mainS.length())
			{
				answer += " ";
			}
		}
		cerr << "Temp: " << answer << endl;
	}

	cerr << answer << endl;
	cout << answer << endl;
}