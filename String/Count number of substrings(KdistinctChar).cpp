//https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1#
//TImeLminitExceded for the code below
// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//time limit exceeded
class Solution
{
    public:
        long long int substrCount (string s, int k)
        {
            int c, n=s.length();
            long long int m=0;
            unordered_map<char, int> hashmap;
            
            
            
            for(int i=0; i<n; i++)
            {
                //cout<<"1"<<endl;
                c=0;
                hashmap.clear();
                
                for(int j=i; j<n; j++)
                {
                    
                   
                    if(hashmap[s[j]]==0) c++;
                    hashmap[s[j]]++;
                    
                    // if count c is equal to distinct element k
                    if(c==k){
                        m++;
                    }
                    
                    // assume repeated no came to the string so c wont increamnet 
                    // whenever other distinct char come it will break out of loop;
                    if(c>k)
                    break;
                    
                }
                
                
            }
            
            return m;
        }
};

// { Driver Code Starts.


int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}  // } Driver Code Ends
