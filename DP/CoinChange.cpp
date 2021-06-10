#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll minimalCoinTD(int sum, ll ar[], int n, vector<ll> &dp)
{
    if (sum == 0)
        return 0;
    if (sum < 0 or n < 0)
        return INT_MAX;

    if (dp[sum] != -1)
    {
        return dp[sum];
    }

    return min(1 + minimalCoinTD(sum - ar[n - 1], ar, n, dp), minimalCoinTD(sum, ar, n - 1, dp));
}

int minimalCoinBU(int n)
{
}

int main()
{
    clock_t begin = clock();

    int n;
    cin >> n;
    ll ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    ll sum;
    cin >> sum;

    //cout<<minimalCoinBU(n)<<"\n";

    vector<ll> dp(sum + 10, -1);

    //cout<<dp.size();

    cout << minimalCoinTD(sum, ar, n, dp) << "\n";

    // for(int i=0; i<n; i++)
    // 	cout<<dp[i]<<"-";

#ifndef ONLINE_JUDGE
    clock_t end = clock();
    cout << "\n\nExecuted In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms";
#endif
    return 0;
}
