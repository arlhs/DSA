//https://practice.geeksforgeeks.org/problems/normal-bst-to-balanced-bst/1#:~:text=The%20task%20is%20to%20complete,updated%20tree%20in%20output%20itself.
//https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return new Node(key);
    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    return node;
}

void preOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int height(struct Node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        int lDepth = height(node->left);
        int rDepth = height(node->right);
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
    return 2;
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node *buildBalancedTree(Node *root);

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        struct Node *root = NULL;
        int n, temp;
        string tree;
        getline(cin, tree);
        root = buildTree(tree);
        // cout<<height(root)<<endl;
        root = buildBalancedTree(root);
        cout << height(root) << endl;
    }
    return 0;
}
// } Driver Code Ends

/*Structure of the Node of the BST is as
struct Node
{
	int data;
	Node* left, *right;
};
*/
// Your are required to complete this function
// function should return root of the modified BST
Node *Insert(Node *root, int data)
{
    if (!root)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = data;
        root->left = root->right = NULL;
        //cout<<"1\n";
    }

    else if (root->data >= data)
        root->left = Insert(root->left, data);
    else if (root->data < data)
        root->right = Insert(root->right, data);

    return root;
}

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    //cout<<root->data<<" ";
    v.push_back(root->data);
    inorder(root->right, v);
}

Node *buildBalancedTree(Node *root)
{
    vector<int> inorderSeq;
    inorder(root, inorderSeq);

    // 	for(int i=0; i<inorderSeq.size(); i++)
    // 	    cout<<inorderSeq[i]<<" ";

    int size = inorderSeq.size();

    //cout<<mid<<"--";

    Node *root1 = NULL;

    int start = 0, end = size;
    int mid = (start + end) / 2;

    while (start < end)
    {
        int mid = (start + end) / 2;
        root1 = Insert(root1, inorderSeq[mid]);
        end = mid;
    }

    while (start < end)
    {
        int mid = (start + end) / 2;
        root1 = Insert(root1, inorderSeq[mid]);
        start = mid + 1;
    }

    // 	 Inorder(root1);
    // 	 cout<<"\n-";

    return root1;
}
