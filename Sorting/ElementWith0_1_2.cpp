// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sorting(int *ar, int n)
{
    int left=0, right=n-1, mid = 0;

    while(mid<=right)
    {
        if(ar[mid]==0)
        {
            swap(ar[mid], ar[left]);
            //mid++;
            left++;
        }
        else if(ar[mid]==2)
        {
            swap(ar[mid], ar[right]);
            //mid++;
            right--;
        }
        mid++;
    }

}

int main()
{
    int n;
    cin>>n;

    int ar[n];

    for(int i=0; i<n; i++)
        cin>>ar[i];
    
    sorting(ar, n);

      for(int i=0; i<n; i++)
        cout << ar[i] << " ";
}
