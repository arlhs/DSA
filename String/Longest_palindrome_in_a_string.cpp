//https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0#

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
    int i=0, j=s.length()-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;

        i++;
        j--;
    }
    return true;
}


string longest_palindrome(string s, int n)
{
    string result ;
    int size=INT_MIN;
    int pos,len;
    
    for(pos=0; pos<n; pos++)
    {
        for(len=1; len<=n-pos; len++)
        {
            string sub = s.substr(pos,len);
            //cout<<palindrome(sub)<<sub<<endl;
            if(palindrome(sub))
            {
                int x = sub.length();
                if(x>size)
                {
                    result = sub;
                    size = sub.length();
                    //cout<<result<<endl;
                }
            }
        }
    }
    
    return result;
}

int main()
 {
	int t;
	cin>>t;
	
	while(t--)
	{
	    string s;
	    cin>>s;
	    int n = s.length();
	    
	    cout<<longest_palindrome(s,n)<<endl;
	    
	    
	}
	return 0;
}
