https://www.geeksforgeeks.org/remove-duplicates-from-a-given-string/

#include<bits/stdc++.h>

using namespace std;

string remove_duplicate(string s, int n)
{
    unordered_map<char, int> hmap;
    int index=0;
    string s1="";
    for(int i=0; s[i]; i++)
    {
        if(hmap[s[i]]==0)
            s1 += s[i];
        hmap[s[i]]++;
    }

    return s1;


}

int main()
{
    string s;
    cin>>s;

    int n = s.length();
    cout<<remove_duplicate(s,n);

    return 0;
}
