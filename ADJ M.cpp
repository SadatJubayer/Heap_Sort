#include <iostream>
#include <cstdio>

using namespace std;


int Adj [100] [100];



int main ()
{

    freopen ("input.txt", "r", stdin);
    int node, edges;
    int n1, n2;

    cin >> node >> edges;


    // creating dynamic 2D array
    int **adj = new int* [node];
    for (int i=0; i<node; i++)
    {
        adj [i] = new int [node];
        for (int j=0; j<node; j++)
        {
            adj [i][j] = 0;
        }
    }


    // taking input of the tree
    for (int i=0; i<edges; i++)
    {
        cin >> n1 >> n2;
        Adj [n1] [n2] = 1;
        Adj [n2] [n1] = 1;    // if the tree is undirected
    }



    cout << "Matrix is: \n" ;
    for (int i =0; i<node; i++)
    {
        for (int j=0; j<node; j++)
        {
            cout << Adj [i][j] <<" ";
        }
        cout << endl;
    }

    int s;
    cin >> s;
    cout << s << " is connected with ";
    for (int k=0; k<node; k++)
    {
        if (Adj [s][k] ==1)
            cout <<k <<" ";
    }

}
