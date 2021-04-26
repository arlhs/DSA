// https://leetcode.com/problems/possible-bipartition/submissions/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool bipartiteBFS(vector<vector<int>> adj, int N, vector<int> &color, int node)
    {
        queue<int> que;
        que.push(node);
        // mark node as colored 1
        color[node] = 1;

        while (!que.empty())
        {
            node = que.front();
            que.pop();

            for (auto nbr : adj[node])
            {
                // if nbr is not colored assign color dif than node 
                if (color[nbr] == 0)
                {
                    color[nbr] = 3 - color[node] % 3;
                    que.push(nbr);
                }
                // if nbr and node is of same color return false i.e, the  graph is not bipartitie
                if (color[nbr] == color[node])
                    return false;
            }
        }

        // if abobe condition satisfied the graphh is bipartite
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        vector<vector<int>> adj(N + 1);

        for (int i = 0; i < dislikes.size(); i++)
        {
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> color(N + 1, 0);

        for (int i = 1; i <= N; i++)
            if (color[i] == 0)
                if (!bipartiteBFS(adj, N, color, i))
                    return false;

        return true;
    }
};