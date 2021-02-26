//https://practice.geeksforgeeks.org/problems/search-pattern0205/1#
//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int m = pat.length();
            int n = txt.length();
            
            int i =0, j=1;
            int lps[m];
            lps[0]=0;
            
            // calculating lps
            while(j<m)
            {
                if(pat[i]==pat[j])
                {
                    i++;
                    lps[j] = i;
                    j++;
                }
                else
                {
                    if(i!=0)
                        i = lps[i-1];
                    else
                    {
                        lps[j] = 0;
                        j++;
                    }
                }
            }
            
            i = j =0;
            vector<int> c;
            
            while(i<n)
            {
                if(txt[i]==pat[j])
                {
                    i++;
                    j++;
                }
                
                if(j==m){   
                    c.push_back(i-j+1);
                    j = lps[j-1];
                }
                
                else if (i < n && pat[j] != txt[i]){
                    if(j!=0)
                        j = lps[j-1];
                    else
                        i++;
                }
                    
            }
            
            if(c.empty())
                c.push_back(-1);
            
            return c;
            
        }
       
    
     
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends
