#include<bits/stdc++.h>

using namespace std;

void subseq(string in, string out)
{
    if(in.empty()){
        cout<<out<<" ";
        return;
    }

    subseq(in.substr(1), out);
    subseq(in.substr(1), out+in[0]);
}

void permutaion(string s, int l, int r)
{
    if(l==r){
        cout<<s<<" ";
        return;
    }

    for(int i=l; i<=r; i++){
        swap(s[l], s[i]);
        permutaion(s, l+1, r);
        swap(s[l], s[i]);
    }
}

int main()
{
    string s;
    cin>>s;

    subseq(s,"");
    permutaion(s,0, s.size()-1);
    cout<<"\n";
}
