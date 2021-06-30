#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long

int value(char ch)
{
    return (int)ch;
}

int rabinKarp(string a, string b)
{
    //const int MAXN = 1000 + 5;
    int p = 31;
    int mod = 1e9 + 9;
    int primeInv = 838709685;

    int n = a.size();
    int m = b.size();

    ull power[m + 1];
    power[0] = 1;

    for (int i = 1; i <= m - 1; i++)
        power[i] = (power[i - 1] * p) % mod;

    // calculating hash for first M size window
    ull hashA = 0, hashB = 0;
    for (int i = 0; i < m; i++)
    {
        hashA = (hashA + value(a[i]) * power[i]) % mod;
        hashB = (hashB + value(b[i]) * power[i]) % mod;
    }

    int count = 0;

    for (int i = 0; i <= n - m; i++)
    {
        if (hashA == hashB)
            count++;
        if (i < n - m)
        {
            hashA = (hashA - value(a[i]) + mod) * primeInv % mod;
            hashA = (hashA + value(a[i + m]) * power[m - 1]) % mod;
        }
    }

    return count;
}

int main()
{
    string a;
    getline(cin, a);

    int q;
    cin >> q;

    while (q--)
    {
        string b;
        cin >> b;

        int count = rabinKarp(a, b);
        cout << count << "\n";
    }
}
