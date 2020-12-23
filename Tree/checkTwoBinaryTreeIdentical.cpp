bool isIdentical(Node *r1, Node *r2)
{
    if(r1==NULL&&r2==NULL){
        return true;
    }else if(r1==NULL){
        return false;
    }else if(r2==NULL){
        return false;
    }else{
        if(r1->data==r2->data)
            return isIdentical(r1->left,r2->left) && isIdentical(r1->right,r2->right);
        else
            return false;
    }
}