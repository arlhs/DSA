// https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
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

// } Driver Code Ends
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
class Solution
{
public:
    // function should print the topView of the binary tree
    vector<int> topView(struct Node *root)
    {
        //Your code here
        vector<int> v;
        if (!root)
            return v;

        map<int, int> value;

        queue<pair<Node *, int>> q;
        int horizontalDist = 0;
        q.push(make_pair(root, horizontalDist));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *current = temp.first;
            horizontalDist = temp.second;

            if (value.find(horizontalDist) == value.end())
                value[horizontalDist] = current->data;

            if (current->left)
                q.push(make_pair(current->left, horizontalDist - 1));
            if (current->right)
                q.push(make_pair(current->right, horizontalDist + 1));
        }

        for (auto it = value.begin(); it != value.end(); it++)
            v.push_back(it->second);

        return v;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, k;
        cin >> n;
        i = n;

        Node *root = NULL;
        queue<Node *> q;
        while (i > 0)
        {
            int a, b;
            char c;
            cin >> a >> b >> c;
            if (!root)
            {
                root = new Node(a);
                q.push(root);
            }
            Node *pick = q.front();
            q.pop();

            if (c == 'L')
            {
                pick->left = new Node(b);
                q.push(pick->left);
            }
            cin >> a >> b >> c;
            if (c == 'R')
            {
                pick->right = new Node(b);
                q.push(pick->right);
            }
            i -= 2;
        }
        //        inorder(root);
        //        cout<<endl;
        Solution obj;
        vector<int> res = obj.topView(root);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends