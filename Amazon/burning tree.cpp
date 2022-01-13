//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
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
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    
    Node* findParents(map<Node*, Node*>&m, Node* root, int target){
        if(root == NULL)
            return NULL;
        
        queue<Node*> q;
        Node* res;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();
            
            if(node->data == target)
                res = node;
            
            if(node->left){
                m[node->left] = node;
                q.push(node->left);
            }    
            if(node->right){
                m[node->right ] = node;
                q.push(node->right);
            }
        }
        return res;
        
    }
    
    int mT( Node* root, map<Node*, Node*>m, Node* target){
        
        queue<Node*> q;
        q.push(target);
        
        map<Node*, int> vis;
        int ans=0;
        vis[target] = 1;
        while(!q.empty())
        {
            int k = q.size();
            int f=0;
            for(int i=0;i<k;i++)
            {
                Node* node = q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    vis[node->left] =1;
                    f=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right] =1;
                    f=1;
                    q.push(node->right);
                }
                
                if(m[node] && !vis[m[node]]){
                    vis[m[node]] =1;
                    f=1;
                    q.push(m[node]);
                }
            }
            
            if(f)
            ans++;
        }
        
        return ans;
            
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        map<Node*, Node*> m;
        Node* res = findParents(m, root, target);
        
        int time = mT(root, m, res);
        return time;
    }
};

// { Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}
  // } Driver Code Ends