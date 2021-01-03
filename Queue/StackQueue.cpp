//https://practice.geeksforgeeks.org/problems/queue-using-two-stacks/1

// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}
// } Driver Code Ends


/* The structure of the class is
class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
}; */

/* The method push to push element into the queue */
void StackQueue :: push(int x)
 {
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{       int n;

        if(s2.size()!=0){       //if s1 stack is not empty pop from it and return;
            n = s2.top();
            s2.pop();
            return n;
        }
            
        if(s1.size()==0)        // if s2 is also empty return -1;
            return -1;
        
        while(!s1.empty()){     // if s2 is empty ans s1 not empty pop from s1 and push into s2 unti s1 is empty;
            n=s1.top();
            s2.push(n);
            s1.pop();
        }
        
        n= s2.top();            // pop from s2 and return;
        s2.pop();
        
        return n;
            
            
}
