#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/
// letcode solution part only
class Solution
{
public:
    int findMinValueNode(vector<int> &value, vector<bool> &setMST)
    {
        int min = INT_MAX;
        int vertex = -1;
        for (int i = 0; i < value.size(); i++)
        {
            if (setMST[i] == false && value[i] < min)
            {
                min = value[i];
                vertex = i;
            }
        }

        return vertex;
    }

    int prims(vector<vector<int>> adjMat, int sizeV)
    {
        vector<int> value(sizeV, INT_MAX);
        vector<bool> setMST(sizeV, false);
        vector<int> parent(sizeV, -1);
        int sum = 0;

        // step 1: source node should have minimum value
        value[0] = 0;

        queue<int> que;

        // MST with min size-1 vertex

        for (int i = 0; i < sizeV - 1; i++)
        {
            // step 2: selecting node with min value and not visited
            int node = findMinValueNode(value, setMST);
            setMST[node] = true;

            // step 3: Relaxing matrix not included setMST
            for (int j = 0; j < sizeV; j++)
            {

                // 3 condition to relax
                // 1. there should be an edge from node to j
                // 2. j should not be in setMST
                // 3. Edge weight should be smaller than the current weight

                if (adjMat[node][j] != 0 && setMST[j] == false && adjMat[node][j] < value[j])
                {
                    
                    value[j] = adjMat[node][j];
                    parent[j] = node;
                }
            }
        }

        for (int i = 0; i < sizeV; i++)
            sum += value[i];

        return sum;
    }

    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int sizeV = points.size();
        vector<vector<int>> adjMat(sizeV, vector<int>(sizeV, 0));

        //memset(adjMat, 0, sizeof(adjMat));

        //    0     1     2     3      4
        // [[0,0],[2,2],[3,10],[5,2],[7,0]]
        // populating adjacant matrix considering them as a node from 0 to size-1

        for (int i = 0; i < sizeV; i++)
        {
            for (int j = i; j < sizeV; j++)
            {
                adjMat[i][j] = abs(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                adjMat[j][i] = abs(abs(points[j][0] - points[i][0]) + abs(points[j][1] - points[i][1]));
            }
        }

        // for(int i=0; i<size; i++){
        //     for(int j=0; j<size; j++)
        //         cout<<adjMat[i][j]<<" ";
        //     cout <<endl;
        // }

        int min = prims(adjMat, sizeV);
        return min;
    }
};