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
	int L;
	cin >> L; cin.ignore();
	int H;
	cin >> H; cin.ignore();
	string T;
	getline(cin, T);
	cerr << T << endl;
	cerr << T.length() << endl;
	for (int i = 0; i < H; i++)
	{
		string ROW;
		getline(cin, ROW);
		//For each line (H)
		string answer = "";

		//For each letter of T

		for (int j = 0; j<T.length(); j++)
		{
			/*
			Every char has a numberic (decimal) representation,
			so we need to check if it is capital (between 65 & 90) or not (between 97 & 122),
			to calculate an int starting at 0 then multiply this value
			for the width and grab the ascii representation
			*/
			//If is capital

			if (T[j] >= 65 && T[j] <= 90)
			{
				//Transpose it on a number between 0 & 25
				int startPos = T[j] - 65;
				//Multiply it for the width and grab the ASCII Representation in this ROW
				//Substract the characters of each letter based on the width
				answer += ROW.substr(startPos*L, L);

			}
			//If not capital
			else if (T[j] >= 97 && T[j] <= 122)
			{
				//Transpose it on a number between 0 & 25
				int startPos = T[j] - 97;
				//Multiply it for the width and grab the ASCII Representation in this ROW
				//Substract the characters of each letter based on the width
				answer += ROW.substr(startPos*L, L);
			}
			//if not between [a-z] or [A-Z]
			else
			{
				//Grab the last ascii representation of ?
				answer += ROW.substr(ROW.length() - L, L);
			}
			
		}
		//Output each row
		cout << answer << endl;
	}

}