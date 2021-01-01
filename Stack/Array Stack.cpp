#include<bits/stdc++.h>
using namespace std;

#define max 100

class Stack{
        int top;
        int stack[max];
public:

    Stack(){
        top=-1;
    }
    void push(int x){
    if(top==max)
        cout<<"\n***Stack is Full***\n";
    else
        stack[++top]=x;
}
    void pop(){
        if(top==-1)
            cout<<"\n***Stack is Empty***\n";
        else
            top--;
    }

    int peek(){
        return stack[top];
    }

    bool isEmpty(){
        if(top==-1)
            return true;
        else
            return false;
    }
};



int main()
{
    struct Stack s;
    int x,c;
    
    while(1){
        printf("\n 1 Push\n 2 Pop\n 3 Top\n 4 Is Empty\n 5 Exit\n");
        cin>>c;

        switch(c){
            case 1: cin>>x;
                    s.push(x);
                    break;
            case 2: s.pop();
                    break;
            case 3: cout<<"Stack top is : "<<s.peek();
                    break;
            case 4: cout<<"Stack is Empty "<<s.isEmpty()<<endl;
                    break;
            case 5: exit(0);
                    break;
        }

    }

}
