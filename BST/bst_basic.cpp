#include<iostream>
#include<queue>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* create_node(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Node* insert(Node* root, int data){

    if(root==NULL)
        root = create_node(data);
    else if(root->data>=data)
        root->left = insert(root->left,data);
    else
        root->right = insert(root->right, data);
    
    return root;
}

int search(Node* root,int key)
{
    if(root==NULL)
        return -1;

    if(root->data==key)
        return 1;
    else if(root->data>=key)
        search(root->left, key);
    else
        search(root->right, key);
}

void inorder(Node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}

void levelOrder(Node* root)
{
    if(root==NULL)  return;
    queue<Node*> q;

    q.push(root);
    cout<<q.front()->data<<" ";

    while(!q.empty()){
        Node* currentNode = q.front();
        if(currentNode->left!=NULL) q.push(currentNode->left);
        if(currentNode->right!=NULL) q.push(currentNode->right);
        cout<<q.front()->data<<" ";
        q.pop();
    }
    
}

Node* findMin(Node* root)
{
    if(root==NULL)
        return NULL;
    while(root->left!=NULL)
        root = root->left;
    
    return root;
}

int findMax(Node* root)
{
    //finMax(15)
    //findMax(20)
    //findMax(25)
    int mx;
    if(root==NULL)                          
        return -1;
    else if (root->right!=NULL)
        return findMax(root->right);
    
    return root->data;
}

int findHeight(Node *root)
{
    if(root==NULL)
        return -1;
    
    return max(findHeight(root->left), findHeight(root->right))+1;
}

Node* DeleteNode(Node* root, int key)
{
    if(root==NULL)  return root;
    else if(root->data>key)
        root->left = DeleteNode(root->left, key);
    else if(root->data<key)
        root->right = DeleteNode(root->right, key);
    else{   //Key need to be deleted is found

        // No child
        if(root->left==NULL && root->right==NULL){
            delete root;
            root = NULL;
            //return root;
        }

        // Only one child i.e., left child only
        else if(root->left==NULL){
            Node* temp = root;
            root = root->right;
            delete temp;
            //return root;
        }

        // Only One child i.e., right child only
        else if(root->right==NULL){
            Node* temp = root;
            root = root->left;
            delete temp;
            //return root;
        }

        // Case 3: two child
        else{
            Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = DeleteNode(root->right,temp->data);
            //return root;
        }
    
    }
    return root;
}

int main()
{
    Node *rootPtr = NULL;

    rootPtr = insert(rootPtr,15);
    rootPtr = insert(rootPtr,10);
    rootPtr = insert(rootPtr,20);
    rootPtr = insert(rootPtr,25);
    rootPtr = insert(rootPtr,8);
    rootPtr = insert(rootPtr,12);

    inorder(rootPtr);
    cout<<"\n";
    // levelOrder(rootPtr);
    // cout<<"2\n";

    // cout<<"S-"<<search(rootPtr, 10)<<" ";
    // cout<<"Max-"<<findMax(rootPtr)<<" ";
    // cout<<"Min-"<<findMin(rootPtr)->data<<" ";
    // cout<<"Height-"<<findHeight(rootPtr)<<" ";

    rootPtr = DeleteNode(rootPtr,20);
    inorder(rootPtr);

}