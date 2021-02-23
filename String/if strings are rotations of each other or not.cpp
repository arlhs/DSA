// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
// Above link have another method using strstr library function

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

int main()
{
    string s1 = "ABACC";
    string s2 = "CDABA";
    
    //if length of string s1 and s2 are not samee then rotation is not possible
    if(s1.length()!=s2.length()){
        cout<<false;
        return 0;
    }
    
    
    s1.append(s1);
    int n=s1.length();

    if(s1.find(s2)<n)
        cout<<true;
    else
        cout<<false;
}
