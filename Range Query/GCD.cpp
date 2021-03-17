//https://www.codechef.com/problems/GCDQ
// https://www.youtube.com/watch?v=e3qhRh4UOug&list=PLauivoElc3ggagradg8MfOZreCMmXMmJ-&index=19
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,q;
        cin>>n>>q;
        int ar[n+10];
        int forward[n+10], backward[n+10];
        forward[0] = backward[n+1] = 0;


        for(int i=1; i<=n; i++)
            cin>>ar[i];
        
        
        //if array having element a b c d 
        // gcd of element a ab abc abcd 
        for(int i=1; i<=n; i++ )
            forward[i] = __gcd(forward[i-1],ar[i]);
        
        //array having gcd of dcba dcb dc d
        for(int i=n; i>=1; i-- )
            backward[i] = __gcd(backward[i+1],ar[i]);

        while(q--)
        {
            int l,r;
            cin>> l >> r;

            cout<< __gcd(forward[l-1], backward[r+1])<<" ";
        }
    }

}
