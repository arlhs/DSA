#include<bits/stdc++.h>

using namespace std;

void insert_bottom(stack<int> &s, int n){

    if(s.empty())
        s.push(n);
    else{

        int x = s.top();
        s.pop();
        insert_bottom(s, n);

        s.push(x);
    }
}

void reverse(stack<int> &s){

    if(!s.empty()){

        int x = s.top();
        s.pop();
        reverse(s);

        insert_bottom(s, x);

    }
}

int main()
{
    int n;
    cin>>n;

    stack<int> s;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.push(x);
    }

    reverse(s);

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    cout<<"\n";
}
