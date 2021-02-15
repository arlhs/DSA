https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// logic start here.

vector <int> max_of_subarrays(int *arr, int n, int k){
    vector<int> max_no;
    
    int i;
    deque<int> qi(k);
    for(i=0; i<k; i++)
    {
        while(!qi.empty() && arr[i]>=arr[qi.back()])
            qi.pop_back();
        
        qi.push_back(i);
    }
    
    for(;i<n;i++)
    {
        max_no.push_back(arr[qi.front()]);
        
        while(!qi.empty() && qi.front()<=i-k)
            qi.pop_front();
        
        while(!qi.empty() && arr[i]>=arr[qi.back()])
            qi.pop_back();
        
        qi.push_back(i);
            
    }
    
    max_no.push_back(arr[qi.front()]);
    
    return max_no;
    
}


// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    
	    vector <int> res = max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends
