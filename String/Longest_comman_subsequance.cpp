//https://www.youtube.com/watch?v=UZRkpGk943Q&t=800s
//https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t,n,k,x,y;
    
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        
        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends


// function to find longest common subsequence

int lcs(int x, int y, string s1, string s2){
    
    int i,j;
    int dp[x+1][y+1] = {0};
    
    for(i=0; i<=x; i++)
    {
        for(j=0; j<=y; j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    
    int s = dp[x][y];
    return s;
}
