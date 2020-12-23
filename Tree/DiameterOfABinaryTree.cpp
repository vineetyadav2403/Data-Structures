int dia(Node* node,int *height){
    int lh=0,rh=0,ldia=0,rdia=0;
    if(!node){
        *height = 0;
        return 0;
    }
    ldia = dia(node->left,&lh);
    rdia = dia(node->right,&rh);
    *height = max(rh,lh) +1;
    return max(lh+rh+1,max(ldia,rdia));
}

int diameter(Node* node) {
    int h=0;
    return dia(node,&h);
}