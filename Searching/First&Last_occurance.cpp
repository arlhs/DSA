// https://www.youtube.com/watch?v=OE7wUUpJw6I&list=PL2_aWCzGMAwL3ldWlrii6YeLszojgH77j&index=4
// https://practice.geeksforgeeks.org/problems/first-and-last-occurrences-of-x3116/1


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
vector<int> find(int a[], int n , int x );

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends


vector<int> find(int arr[], int n , int x )
{
    int low=0, high=n-1;
    vector<int> fl;
    fl.push_back(-1);
    fl.push_back(-1);
    int result=-1;
    
    while(low<=high)
    {
        
        int mid = low + (high-low)/2;
        if(arr[mid]==x)
        {
            result = mid;
            high = mid-1;
        }
        
        else if(arr[mid]>=x)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    
    fl[0]=result;
    
     low=0, high=n-1;
    
     while(low<=high)
    {
        
        int mid = low + (high-low)/2;
        if(arr[mid]==x)
        {
            result = mid;
            low = mid+1;
        }
        
        else if(arr[mid]>=x)
            high = mid - 1;
        else 
            low = mid + 1;
    }
    
    fl[1]=result;
    
    return fl;
}
