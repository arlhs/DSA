https://www.youtube.com/watch?v=Q3iTTwgDb6U

// { Driver Code Starts
#include <bits/stdc++.h>
#include <string>
using namespace std;

const int no_of_chars = 256;

int findSubString(string str);

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;

        cout << findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends




int findSubString(string s)
{
    unordered_map<int, int> hash_map;
    unordered_map<int, int> value;
    
    for(int i=0; s[i]; i++)
        hash_map[s[i]]++;
    
    string result="";
    
        
    int distinct_count = hash_map.size();
    
    int start=0, end=1;
    int count=0;
    
    value[s[0]]++;
    count++;
    
    //int value[256] ={0};
    int mi=INT_MAX;
    
   while(start<=end && end<s.size())
   {
       if(count<distinct_count)
       {
           if(value[s[end]]==0) count++;
           value[s[end]]++;
           //result += s[end];
           end++;
       }
       else if(count==distinct_count)
       {
            mi = min(mi,end-start);
           if(value[s[start]]==1) count--;
           value[s[start]]--;
           //result.erase(result.begin() + start-1 );
           start++;
       }
   }
   while(count==distinct_count)
   {
       mi = min(mi,end-start);
       if(value[s[start]]==1) count--;
       value[s[start]]--;
        //result.erase(result.begin() + start -1 );
       start++;
   }
   
  
    return mi;
    // result;
}
