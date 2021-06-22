#include <bits/stdc++.h>
using namespace std;

int upperBound(int ar[], int n, int key)
{
    int low = 0, hi = n - 1;
    int mid;
    while (low <= hi)
    {
        mid = (low + hi) / 2;
        if (ar[mid] == key)
            low = mid + 1;
        else if (ar[mid] < key)
            low = mid + 1;
        else if (ar[mid] > key)
            hi = mid - 1;
    }

    return low;
}

int main()
{
    int n;
    cin >> n;

    int ar[n];

    for (int i = 0; i < n; i++)
        cin >> ar[i];

    int x;
    cin>>x;
    int idx = upperBound(ar, n, x);
    cout << idx;
}

/*
Sample input 
10 
1 3 5 5 5 6 6 7 9 9 
5
output: 5
*/