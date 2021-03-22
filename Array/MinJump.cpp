// https://practice.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1#
// For better understanding go for editorial of gfg
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array
int minJumps(int arr[], int n){
    // Your code here
    
    if(arr[0]==0)
        return -1;
    else if(n==1)
        return 1;
    
    //step need to search for maximum indexing
    int step=arr[0];
  
    //maximum reach withing the steps
    int mx=arr[0];
  
    // no of jumps to take;
    int jump=1;
    
    for(int i=1; i<n; i++){
        if(i==n-1)
            return jump;
        
      // finding max reache of index;
        mx = max(mx, i+arr[i]);
        
        step--;
        
        //when we searcher for each steps
        if(step==0)
        {
            jump ++;

            // 2 1 0 3 for 0th element in the array
            if(i>=mx)
                return -1;
            
            // no of step tp be checked for maximum index 
            step = mx - i;
        }
    }
    

    return -1;
}



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends
