#include <bits/stdc++.h>

using namespace std;

int findMinWt(vector<int> &value, vector<bool> &processed)
{
    int val = INT_MAX;
    int vertex;
    for (int i = 0; i < value.size(); i++)
    {
        if (val > value[i] && processed[i] == false)
        {
            val = value[i];
            vertex = i;
        }
    }

    return vertex;
}

void dijkstra(vector<vector<int>> &adjMat, int node)
{
    int V = adjMat.size();

    vector<int> value(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> processed(V, false);

    // initialising initial node value to minimum
    value[node] = 0;

    for (int i = 0; i < V - 1; i++)
    {

        node = findMinWt(value, processed);
        processed[node] = true;

        for (int nbr = 0; nbr < V; nbr++)
        {

            if (adjMat[node][nbr] != 0 && processed[nbr] == false &&
                value[node] != INT_MAX && value[node] + adjMat[node][nbr] < value[nbr])
            {
                value[nbr] = value[node] + adjMat[node][nbr];
                parent[nbr] = node;
            }
        }
    }

    for (int i = 1; i < V; ++i)
        cout << "U->V: " << parent[i] << "->" << i << "  wt = " << adjMat[parent[i]][i] << "\n";
}

int main()
{
    // int V, E;
    // cin>>V;

    vector<vector<int>> adjMat = {{0, 1, 4, 0, 0, 0},
                                  {1, 0, 4, 2, 7, 0},
                                  {4, 4, 0, 3, 5, 0},
                                  {0, 2, 3, 0, 4, 6},
                                  {0, 7, 5, 4, 0, 7},
                                  {0, 0, 0, 6, 7, 0}};

    // vector<vector<int> adjMat(V, (V, 0));

    // for(int i=0; i<E; i++){
    // 	int from, to, w;
    // 	cin>>from>>to>>w;
    // 	adjMat[from][to] = w;
    // 	adjMat[to][from] = w;
    // }

    dijkstra(adjMat, 0);
}