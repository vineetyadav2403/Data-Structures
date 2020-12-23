int path(Node* root, int &res){
    if (root==NULL) return 0; 
    if (!root->left && !root->right) return root->data; 

    int ls = path(root->left, res); 
    int rs = path(root->right, res); 
  

    if (root->left && root->right) 
    { 

        res = max(res, ls + rs + root->data); 
  
        return max(ls, rs) + root->data; 
    } 

    return (!root->left)? rs + root->data: ls + root->data; 
}
int maxPathSum(Node* root)
{ 
    int res = INT_MIN;
    path(root,res);
    return res;
    
}