#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int hd;
    int data; //data of the node
    Node *left, *right; //left and right references
    Node(int key)
    {
        hd = INT_MAX;
        data = key;
        left = right = NULL;
    }
};

// if class have hd variable
vector <int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL) 
        return; 
    int hd = 0; 
    map<int, int> m; 
    queue<Node *> q; 

    root->hd = hd; 
    q.push(root);
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop();
        hd = temp->hd;
        m[hd] = temp->data;  
        if (temp->left != NULL) 
        { 
            temp->left->hd = hd-1; 
            q.push(temp->left); 
        } 
        if (temp->right != NULL) 
        { 
            temp->right->hd = hd+1; 
            q.push(temp->right); 
        } 
    } 
 
    for (auto i = m.begin(); i != m.end(); ++i) 
        ans.push_back(i->second);
    return ans; 
}

// if class do not have hd varial

vector <int> bottomView(Node *root)
{
    vector<int> ans;
    if (root == NULL) 
        return ans; 
    int hd = 0; 
    map<int, int> m; 
    queue<Node *> q; 
    unordered_map<Node*, int> mp;
    mp[root] = hd;
    q.push(root);
    while (!q.empty()) 
    { 
        Node *temp = q.front(); 
        q.pop();
        hd = mp[temp];
        m[hd] = temp->data;  
        if (temp->left != NULL) 
        { 
            mp[temp->left] = hd-1; 
            q.push(temp->left); 
        } 
        if (temp->right != NULL) 
        { 
            mp[temp->right] = hd+1; 
            q.push(temp->right); 
        } 
    } 
 
    for (auto i = m.begin(); i != m.end(); ++i) 
        ans.push_back(i->second);
    return ans; 
}