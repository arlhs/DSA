// https://practice.geeksforgeeks.org/problems/merge-sort-on-doubly-linked-list/1
// Link to geeksforgeeks problem

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};


 // } Driver Code Ends


/*
Structure of the node of the list is as
struct Node
{
	int data;
	struct Node *next, *prev;
	Node (int x){
	    data = x;
	    next = prev = NULL;
	}
}; */


// Function to merge two DLLs

struct Node *merge(struct Node *left,struct Node *right)
{
    Node *sorted = new Node(0);
    Node *current = sorted;
    
    while(left!=NULL && right!=NULL){
        if(left->data>right->data){
            current->next=left;
            left=left->next;
        }
        else{
            current->next=right;
            right=right->next;
        }
        current=current->next;
    }
    
    if(left!=NULL){
        current->next=left;
    }
    else{
        current->next=right;
    }
    
    return sorted->next;
}

struct Node *sortDoubly(struct Node *head)
{
	if(head==NULL || head->next==NULL)
	    return head;
	   
	Node *temp=head, *slow=head, *fast=head;
	Node *sorted=NULL;
	
	while(fast!=NULL && fast->next!=NULL){
	    temp=slow;
	    slow=slow->next;
	    fast=fast->next->next;
	}
	
	temp->next=NULL;
	
	Node *leftList=sortDoubly(head);
	Node *rightList=sortDoubly(slow);
	
	return merge(leftList,rightList);
	//return NULL;
}




// { Driver Code Starts.

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

void print(struct Node *head)
{
	struct Node *temp = head;
	while (head)
	{
		cout<<head->data<<' ';
		temp = head;
		head = head->next;
	}
	cout<<endl;
	while (temp)
	{
		cout<<temp->data<<' ';
		temp = temp->prev;
	}
	cout<<endl;
}

// Utility function to swap two integers
void swap(int *A, int *B)
{
	int temp = *A;
	*A = *B;
	*B = temp;
}


// Driver program
int main(void)
{
    long test;
    cin>>test;
    while(test--)
    {
        int n, tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            insert(&head, tmp);
        }
        head = sortDoubly(head);
        print(head);
    }
	return 0;
}
  // } Driver Code Ends
