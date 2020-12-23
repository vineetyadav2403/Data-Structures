int height(struct Node* node){
        if(!node) return 0;
        
        int l = height(node->left);
        int h = height(node->right);
        
        int temp = 1+max(l,h);
        return temp;
}