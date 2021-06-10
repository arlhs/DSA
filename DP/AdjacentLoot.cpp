#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxLoot(vector<int> ar, vector<int> &dp, int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return dp[n] = ar[n];
    if (n == 1)
        return dp[n] = max(ar[n], ar[n - 1]);

    if (dp[n] != -1)
        return dp[n];

    dp[n] = max(maxLoot(ar, dp, n - 1), maxLoot(ar, dp, n - 2) + ar[n]);
    return dp[n];
}

int main()
{
    int n;
    //4 
    //6 2 4 9
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    vector<int> dp(n + 2, 0);

    int mx = INT_MIN;

    // Iterative
    for (int i = 2; i <= n + 1; i++)
    {
        dp[i] = max(ar[i - 2] + dp[i - 2], dp[i - 1]);
        //cout<<dp[i];
        if (mx < dp[i])
            mx = dp[i];
    }

    vector<int> dpLoot(n, -1);

    int res = maxLoot(ar, dpLoot, n - 1);

    for (int i = 0; i < dpLoot.size(); i++)
        cout << dpLoot[i] << " ";

    cout << mx << " " << res;
}
