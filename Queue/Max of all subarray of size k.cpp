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
	// if deque is not empty and cur_elemet is greater than the last element then pop_back
        while(!qi.empty() && arr[i]>=arr[qi.back()])
            qi.pop_back();
        
	// else if deque is empty or the cur_element is smaller than last element of deque
        qi.push_back(i);
    }
    
    for(;i<n;i++)
    {
	//pushing the mfront of deque(max of size k subarray) 
        max_no.push_back(arr[qi.front()]);
        
	//checking is the max of previsous will lie in current window or not
        while(!qi.empty() && qi.front()<=i-k)
            qi.pop_front();
        
	// same as the intital step for 1st window of size k
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
