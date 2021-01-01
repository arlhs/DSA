#include<iostream>
using namespace std;

class Stack{
public:
    int data;
    struct Stack *next;

    Stack(int x){
        data=x;
        next=NULL;
    }
};

struct Stack *push(struct Stack *top, int x){

    if(top==NULL)
        top = new Stack(x);
    else{
        Stack *temp = new Stack(x);
        temp->next=top;
        top = temp;
    }

    return top;
}

struct Stack *pop(struct Stack *top)
{
    if(top->next==NULL)
        delete top;
    else{
        Stack *temp = top;
        top=top->next;
        delete temp;
    }

    return top;
}

int peek(struct Stack *top)
{
    if(top)
        return top->data;
    else
        return -1;
}
bool isEmpty(struct Stack *top)
{
    if(top)
        return false;
    else return true;
}
int main()
{
    Stack *top=NULL;
    int x,c;

   while(1){
        printf("\n1 Push\n 2 Pop\n 3 Top\n 4 Is Empty\n 5 Exit\n\n");
        cin>>c;

        switch(c){
            case 1: cin>>x;
                    top = push(top,x);
                    break;
            case 2: top = pop(top);
                    break;
            case 3: cout<<peek(top);
                    break;
            case 4: cout<<isEmpty(top)<<endl;
                    break;
            case 5: exit(0);
                    break;
        }

    }
}
