#include<bits/stdc++.h>
using namespace std;

class Stack{
    int *ar;
    int top=-1;

public:
    Stack(int n){
        ar = new int[n];
    }

    void push(int x);
    void pop();
    int toop();
    int size();

};

void Stack::push(int x){
    top++;
    ar[top] = x;
}

void Stack:: pop(){
    top--;
}

int Stack::toop(){
    return ar[top];
}

int Stack:: size(){
    return top+1;
}


int main()
{
    Stack s(10);

    int n; cin>>n;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        s.push(x);
    }

    for(int i=0; i<n; i++){
        cout<<s.toop()<<" ";
        s.pop();
    }
}
