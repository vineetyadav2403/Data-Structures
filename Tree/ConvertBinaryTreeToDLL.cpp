void BToDll(Node *root,Node* &head){
    if(!root) return;
    
    BToDll(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left = root;
    }
    head=root;
    BToDll(root->left,head);
    
}

Node * bToDLL(Node *root)
{
    Node * head=NULL;
    BToDll(root,head);
    return head;
}