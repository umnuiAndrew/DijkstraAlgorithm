#include <iostream>
#define INF 0x3f3f3f3f
#define MAX_VERTICES 4
using namespace std;

int V = 4;

int graph[MAX_VERTICES][MAX_VERTICES] = {
    {0, 5, INF, 10},
    {INF, 0, 3, INF},
    {INF, INF, 0, 1},
    {INF, INF, INF, 0}};
int P[MAX_VERTICES][MAX_VERTICES]; // Array of predecessors, used to trace the paths
int D[MAX_VERTICES][MAX_VERTICES]; // Distance matrix, stores the shortest distance between all pairs of vertices

void getPath(int a, int b)
{
    if (P[a][b] == b)
    {
        cout << b << " ";
        return;
    }
    getPath(a, P[a][b]);
    cout << b << " ";
}

void printSolution()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << "from " << i << " to " << j << " : ";
            if (D[i][j] == INF)
            {
                cout << "-" << endl;
                continue;
            }
            else
            {
                cout << D[i][j] << endl;
                getPath(i, j);
                cout << endl;
            }
        }
        cout << endl;
    }
}

void floydWarshall()
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            D[i][j] = graph[i][j];
            P[i][j] = i;
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (D[i][k] + D[k][j] < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
    }
    printSolution();
}
int main()
{
    floydWarshall();
    // getPath(1,3);
    return 0;
}