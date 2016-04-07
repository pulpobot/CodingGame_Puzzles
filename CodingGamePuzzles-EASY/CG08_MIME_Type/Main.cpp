#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
//Add library to include toupper function
#include <cctype> 
using namespace std;

/**
* Auto-generated code below aims at helping you parse
* the standard input according to the problem statement.
**/
int main()
{
	int N; // Number of elements which make up the association table.
	cin >> N; cin.ignore();
	int Q; // Number Q of file names to be analyzed.
	cin >> Q; cin.ignore();
	//Multidimensional array to hold ext - MIME to compare later
	string MIME[N][2] = {};
	//For each MIME type
	for (int i = 0; i < N; i++)
	{
		string EXT; // file extension
		string MT; // MIME type.
		cin >> EXT >> MT; cin.ignore();
		//transform the EXT to uppercase
		for (int i = 0; i<EXT.length(); i++)
		{
			EXT[i] = toupper(EXT[i]);
		}
		//Save both on the array
		MIME[i][0] = EXT;
		MIME[i][1] = MT;
		cerr << MIME[i][0] << " -- " << MIME[i][1] << endl;
	}

	//For each file
	for (int i = 0; i < Q; i++)
	{
		string FNAME; // One file name per line.
		string FEXT;
		getline(cin, FNAME);
		cerr << "File: " << FNAME << " -- " << FNAME.length() - 1 << endl;
		//Search for the first dot to get the extension
		for (int j = FNAME.length() - 1; j >= 0; j--)
		{
			if (FNAME[j] == '.')
			{
				if (j != FNAME.length() - 1)
				{
					FEXT = FNAME.substr(j + 1, FNAME.length() - 1);
					break;
				}
				else
				{
					FEXT = '.';
					break;
				}
			}

		}
		for (int i = 0; i<FEXT.length(); i++)
		{
			FEXT[i] = toupper(FEXT[i]);
		}
		cerr << "File Ext:" << FEXT << endl;
		bool found = false;
		for (int j = 0; j<N; j++)
		{
			if (FEXT == MIME[j][0])
			{
				cerr << "Founded!" << endl;
				cout << MIME[j][1] << endl;
				found = true;
				break;
			}
		}
		if (!found)
		{
			cout << "UNKNOWN" << endl; // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
		}
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;

}