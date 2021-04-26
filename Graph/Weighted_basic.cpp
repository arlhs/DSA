#include<bits/stdc++.h>
using namespace std;

void addNode(map<int, list<pair<int, int>>> &adj, int u, int v, int w)
{
    // this is for undirected graph
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});    // remove this line for directed graph
}

void bfs(map<int, list<pair<int, int>>> adj, int node)
{
    vector<bool> visited(adj.size(), false);

    queue<pair<int,int>> q;
    auto it = adj[node].begin();
    visited[it->first] = true;
    //cout<<it->first;
    q.push({it->first, it->second});

    while(!q.empty()){
        pair<int, int> temp = q.front();
        int dest = temp.first;
        q.pop();
        //cout<<temp.first<<" ";
        cout<<node<<"->"<<temp.first<<" weighted: "<<temp.second<<"\n";

        for(it = adj[dest].begin(); it!=adj[dest].end(); it++){
            if(!visited[it->first]){
                visited[it->first] = true;
                q.push({it->first, it->second});
            }
        }

    }


}

int main()
{
    map<int, list<pair<int,int>>> adj;

    addNode(adj, 0, 0, 0);
    addNode(adj, 0, 1, 5);
    addNode(adj, 0, 2, 3);
    addNode(adj, 0, 3, 7);
    addNode(adj, 1, 4, 2);
    addNode(adj, 2, 5, 4);
    addNode(adj, 3, 5, 6);
    addNode(adj, 4, 6, 9);
    addNode(adj, 5, 7, 10);
    addNode(adj, 5, 8, 7);
    addNode(adj, 6, 9, 5);
    addNode(adj, 7, 9, 3);
    addNode(adj, 8, 9, 8);

    bfs(adj, 0);
}