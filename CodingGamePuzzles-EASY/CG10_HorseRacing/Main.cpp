#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <climits>
using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    
    int pi[N] = {}; 

    for (int i = 0; i < N; i++) 
    {
        cin >> pi[i]; cin.ignore();
    }
    
    //Sort the array
    sort(pi, pi+N);
    
    //Define the max distance
    int minorDif = INT_MAX;
    //For each value, compare with the next one O(n), and find the min distance
    for (int i = 0; i < N-1; i++) 
    {
        cerr << pi[i+1] << " " << pi[i] << endl;

        if(pi[i+1] - pi[i] < minorDif)
        {
            minorDif = pi[i+1] - pi[i];
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << minorDif << endl;
}
