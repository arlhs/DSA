// https: //www.youtube.com/watch?v=hwCWi7-bRfI&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=16
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

void solve()
{
}

int main()
{
    clock_t begin = clock();
    file_i_o();

    int t = 1;
    cin >> t;

    // Input
    /*  1   TC
        9   V
        0 1 
        0 3
        1 2
        1 3
        2 6
        3 4
        4 5
        5 6
        6 7
        6 8
        7 8     */

    while (t--)
    {
        int v;
        cin >> v;

        vector<int> adj[v];

        for (int i = 0; i < v; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src = 0;

        queue<int> que;
        que.push(src);

        int cost[v];
        for (int i = 0; i < v; i++)
        {
            cost[i] = INT_MAX;
        }

        cost[src] = 0;

        while (!que.empty())
        {
            int node = que.front();
            que.pop();
            //cout<<node<<"\n";

            for (auto nbr : adj[node])
            {
                if (cost[node] + 1 < cost[nbr])
                {
                    cost[nbr] = cost[node] + 1;
                    que.push(nbr);
                }
            }
        }

        cout << cost[6];

        solve();
    }

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
