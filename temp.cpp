#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> graph = {{0, 1, 4, 0, 0, 0},
                                {1, 0, 4, 2, 7, 0},
                                {4, 4, 0, 3, 5, 0},
                                {0, 2, 3, 0, 4, 6},
                                {0, 7, 5, 4, 0, 7},
                                {0, 0, 0, 6, 7, 0}};

    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++)
            cout<<graph[i][j]<<" ";
        cout<<endl;
    }
}