// { Driver Code Starts
// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1#

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
    public:
    void sort012(int ar[], int n)
    {
        int left=0, right=n-1, mid = 0;

    while(mid<=right)
    {
        //left will always be sorted as we have initialised left and mid with 0
        // thus we increment mid and  left for ar[mid]==0
        if(ar[mid]==0)
            swap(ar[left++], ar[mid++]);
            
        //When ar[mid]==2 we don't incremnent mid as the ar[right] can be 0,1 or 2
        //Thus we only decremnet the right;
        else if(ar[mid]==2)
            swap(ar[mid], ar[right--]);
            
            //ar[mid]==1. it is at correct place
        else 
            mid++;
    }
    }
    
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}

  // } Driver Code Ends
