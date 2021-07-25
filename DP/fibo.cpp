#include<bits/stdc++.h>

using namespace std;
int memo[100];
int fibo(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;

    return fibo(n-1) + fibo(n-2);
}

int fiboMemo(int n){

    if(n==0)
        return 0;
    if(n==1)
        return 1;

    if(memo[n]!=-1)
        memo[n];

    memo[n] = fiboMemo(n-1) + fiboMemo(n-2);
    return memo[n];
}

int fiboDP(int n){

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

// 0 1 1 2 3 5 8 13
int main()
{
    int n;
    cin>>n;

    memset(memo, -1, sizeof(memo));
    cout<<fiboDP(n);
}
