#include <bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    struct Node* left, *right; 
      
    Node(int data) 
    { 
        this->data = data; 
        left = right = NULL; 
    } 
}; 


bool isBSTUtil(struct Node* root, Node *&prev) 
{ 
    
    if (root) 
    { 
        if (!isBSTUtil(root->left, prev)) 
          return false; 
    
        if (prev != NULL && root->data <= prev->data) 
          return false; 
   
        prev = root; 
   
        return isBSTUtil(root->right, prev); 
    } 
   
    return true; 
}

// check given tree is binary tree

bool isBST(Node* root) {
   Node *prev = NULL; 
   return isBSTUtil(root, prev); 
    
}