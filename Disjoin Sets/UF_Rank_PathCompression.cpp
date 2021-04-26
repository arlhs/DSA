// https://www.youtube.com/watch?v=kaBX2s3pYO4&list=PLEJXowNB4kPzByLnnFYNSCoqtFz0VKLk5&index=16
#include <iostream>
#include <vector>

using namespace std;

struct node
{
    int parent;
    int rank;
};

// node is defined as index and parent the value store in it
vector<node> dsuf;

int find(int V)
{
    if (dsuf[V].parent == -1)
        return V;
    return dsuf[V].parent = find(dsuf[V].parent); // path compression
}

void UnionOp(int fromP, int toP)
{
    if (dsuf[fromP].rank > dsuf[toP].rank)
        dsuf[toP].parent = fromP;
    else if (dsuf[fromP].rank < dsuf[toP].rank)
        dsuf[fromP].parent = toP;
    else
    {
        dsuf[fromP].parent = toP;
        dsuf[fromP].rank++;
    }
}

bool isCycle(vector<pair<int, int>> &edgeList)
{
    int fromP, toP;
    for (auto edge : edgeList)
    {

        // find absolute parent of from and to
        fromP = find(edge.first);
        toP = find(edge.second);

        // if from and to absolute parent is equal then cycle is present
        // and return
        if (fromP == toP)
            return true;

        // otherwise make union of them
        UnionOp(fromP, toP); // union of 2 set
    }

    //return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    dsuf.resize(V);
    for (int i = 0; i < V; i++)
    {
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    vector<pair<int, int>> edgeList;

    for (int i = 0; i < E; i++)
    {
        int from, to;
        cin >> from >> to;
        edgeList.push_back({from, to});
    }

    if (isCycle(edgeList))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }
}