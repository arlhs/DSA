#include<iostream>
#include<stack>

using namespace std;

void insertBottom(stack<int> &stk, int temp)
{
	if(stk.empty())
		stk.push(temp);
	else{

		int n = stk.top();
		stk.pop();
		insertBottom(stk, temp);

		stk.push(n);
	}
}

void reveresStack(stack<int> &stk)
{
	if(stk.size()>0){

		int temp = stk.top();
		stk.pop();
		reveresStack(stk);

		insertBottom(stk, temp);
	}
}

void print(stack<int> stk)
{
	while(stk.empty()==false){
		int temp = stk.top();
		stk.pop();
		cout<<temp<<endl;
	}
}

int main()
{
    stack<int> stk;
    int n;
    // size of stack
    cin>>n;

    // input
    for(int i=0; i<n; i++){
    	int x;
    	cin>>x;
    	stk.push(x);
    }

    reveresStack(stk);

    print(stk);
}