#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/

struct node
{
    int value;
    int visited;
};

void BFSNodes(vector< vector<node> > &cells, int height, int width, int i, int j);

int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();

    vector< vector<node> > cells(height, vector<node>(width));
    node aux;
    for (int i = 0; i < height; i++) 
    {
        string line; // width characters, each either 0 or .
        getline(cin, line);

        for (int j = 0; j < width; ++j)
        {
            aux.visited = false;
            if(line[j] != '.')
            {
                aux.value = 48 - line[j];
                cells[i][j] = aux;
            }
            else
            {
                aux.value = -1;
                cells[i][j] = aux;
            }
        }
    }

    for (int i = 0; i < height; i++) 
    {

        for (int j = 0; j < width; ++j)
        {
            if(cells[i][j].value == 0)
            {
                BFSNodes(cells, height, width, i, j);
            }
        }
        cerr << endl;
    }

   for (int i = 0; i < height; i++) 
    {

        for (int j = 0; j < width; ++j)
        {
            cerr << cells[i][j].value << " ";
        }
        cerr << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    // Three coordinates: a node, its right neighbor, its bottom neighbor
    // cout << "0 0 1 0 0 1" << endl;
}

void BFSNodes(vector< vector<node> > &cells, int height, int width, int i, int j)
{

    cells[i][j].visited = true;

    node u = cells[i][j];

    string x1, y1, x2, y2, x3, y3;
    y1 = to_string(i);
    x1 = to_string(j);
    cerr << "x1: " << x1 << endl;

    x2 = y2 = x3 =  y3 = to_string(-1);

    //Search Right
    for (int k = j+1; k < width; ++k)
    {
        if(cells[i][k].value == 0)
        {
            y2 = to_string(i);
            x2 = to_string(k);
            break;
        }
    }

    //Search Bottom
    for (int k = i+1; k < height; ++k)
    {
        if(cells[k][j].value == 0)
        {
            y3 = to_string(k);
            x3 = to_string(j);
            break;
        }
    }

    // cerr << "x1: " << x1 << endl;

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << endl;
}
