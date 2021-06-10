// Question Link- https://practice.geeksforgeeks.org/problems/box-stacking/1
// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*The function takes an array of heights, width and 
    length as its 3 arguments where each index i value 
    determines the height, width, length of the ith box. 
    Here n is the total no of boxes.*/
    struct box
    {
        int l, w, h;
    };

    bool cmp(const box &a, const box &b)
    {
        return (a.l * a.w) > (b.l * b.w);
    }

    int maxHeight(int height[], int width[], int length[], int n)
    {
        vector<box> boxes;

        for (int i = 0; i < n; i++)
        {
            boxes.push_back({});
            boxes[3 * i].h = height[i];
            boxes[3 * i].w = max(width[i], length[i]);
            boxes[3 * i].l = min(width[i], length[i]);
            boxes.push_back({});
            boxes[3 * i + 1].h = width[i];
            boxes[3 * i + 1].w = max(length[i], height[i]);
            boxes[3 * i + 1].l = min(length[i], height[i]);
            boxes.push_back({});
            boxes[3 * i + 2].h = length[i];
            boxes[3 * i + 2].w = max(width[i], height[i]);
            boxes[3 * i + 2].l = min(width[i], height[i]);
        }

        int lis[3 * n];

        sort(boxes.begin(), boxes.end(), [](const box &a, const box &b)
             { return (a.l * a.w) > (b.l * b.w); });

        for (int i = 0; i < 3 * n; i++)
        {
            lis[i] = boxes[i].h;
            //cout<<lis[i]<<" ";
        }
        //cout<<"\n";

        // for(int i=0; i<3*n; i++){
        //     cout<<boxes[i].h<<" "<<boxes[i].l<<" "<<boxes[i].w<<"\n";
        // }

        int mx = 0;

        for (int i = 1; i < 3 * n; i++)
        {
            //cout<<"true\n";
            for (int j = 0; j < i; j++)
            {
                //cout<<"true\n";
                if (boxes[i].w < boxes[j].w && boxes[i].l < boxes[j].l && lis[i] < (lis[j] + boxes[i].h))
                {
                    //cout<<"true\n";
                    //cout<<"false\n";
                    lis[i] = lis[j] + boxes[i].h;
                }
                mx = max(mx, lis[i]);
            }
        }

        // return mx>0? mx: lis[3*n-1];
        return mx;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int A[105], B[105], C[105];
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int j = 0; j < n; j++)
            cin >> B[j];
        for (int k = 0; k < n; k++)
            cin >> C[k];
        Solution ob;
        cout << ob.maxHeight(A, B, C, n) << endl;
    }

    return 0;
}
// } Driver Code Ends