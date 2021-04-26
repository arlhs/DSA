// https://www.youtube.com/watch?v=eTaWFhPXPz4&list=PLEJXowNB4kPzByLnnFYNSCoqtFz0VKLk5&index=15

#include <iostream>
#include <vector>

using namespace std;

// node is defined as index and parent the value store in it
vector<int> parent;

int find(int V)
{
    if (parent[V] == -1)
        return V;
    return find(parent[V]);
}

void UnionOp(int fromP, int toP)
{
    fromP = find(fromP);
    toP = find(toP);

    // assigne fromP parent as toP
    parent[fromP] = toP;
}

bool isCycle(vector<pair<int, int>> &edgeList)
{
    int fromP, toP;
    for (auto edge : edgeList)
    {

        // find the parent of from and to
        fromP = find(edge.first);
        toP = find(edge.second);

        // if from and to parent is equal then cycle is present
        // and return
        if (fromP == toP)
            return true;

        // otherwise make union of them
        UnionOp(fromP, toP);
    }

    //return false;
}

int main()
{
    int V, E;
    cin >> V >> E;

    parent.resize(V, -1);
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