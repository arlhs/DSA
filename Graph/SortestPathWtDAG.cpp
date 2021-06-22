// https : //www.youtube.com/watch?v=CrxG4WJotgg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=17

#include <iostream>
#include <bits/stdc++.h>

        using namespace std;

#define ll long long
#define mod 1000000007
#define inf LONG_MAX

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void topoPath(vector<pair<int, int>> adj[], int node, int *visited, stack<int> &stk)
{
    visited[node] = 1;
    //cout<<node<<" ";

    for (auto nbr : adj[node])
    {
        if (visited[nbr.first] == 0)
            topoPath(adj, nbr.first, visited, stk);
    }
    //cout<<"-"<<node<<" ";
    stk.push(node);
}

int main()
{
    clock_t begin = clock();
    file_i_o();

    int t = 1;
    //cin>>t;

    while (t--)
    {
        /* input
    6
    7
    0 1 2
    0 4 1
    1 2 3
    2 3 6
    4 2 2
    4 5 4
    5 3 1   */

        int v, e;
        cin >> v >> e;

        vector<pair<int, int>> adj[v];

        for (int i = 0; i < e; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            //cout<<adj[u][0].first<<" "<<adj[u][0].second<<"\n";
        }

        stack<int> stk;
        int visited[v];
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
                topoPath(adj, i, visited, stk);
        }

        int cost[v];
        for (int i = 0; i < v; ++i)
        {
            cost[i] = INT_MAX;
        }
        cost[0] = 0;

        //cout<<stk.size();

        while (!stk.empty())
        {
            int node = stk.top();
            stk.pop();
            //cout<<node<<" ";

            if (cost[node] != INT_MAX)
            {
                for (auto nbr : adj[node])
                {
                    if (cost[node] + nbr.second < cost[nbr.first])
                        cost[nbr.first] = cost[node] + nbr.second;
                }
            }
        }

        for (int i = 0; i < v; i++)
            cost[i] == INT_MAX ? cout << "INF " : cout << cost[i] << " ";
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
