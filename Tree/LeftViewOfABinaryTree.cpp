#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
};


// left view of a binary tree using BFS
vector<int> leftView(Node *root)
{   
    queue<Node*> q;
    vector<int> ans;
    if (root == NULL) 
        return {}; 
  
    q.push(root); 
    q.push(NULL); 
    while (!q.empty()) { 
        Node* temp = q.front(); 
  
        if (temp) { 
            ans.push_back(temp->data);
            
            while (q.front() != NULL) { 
                if (temp->left) 
                    q.push(temp->left); 

                if (temp->right) 
                    q.push(temp->right); 

                q.pop(); 
  
                temp = q.front(); 
            } 

            q.push(NULL); 
        } 
        q.pop(); 
    }
    return ans;
}