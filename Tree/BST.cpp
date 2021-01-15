#include<iostream>
using namespace std;

class BST{
    public:
        int data;
        BST *left,*right;
        BST(){
            this->data = 0;
            this->left = NULL;
            this->right = NULL;
        }
        BST(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }
};

BST *findMax(BST *root){
    if(!root) return root;
    while(!root->right){
        root = root->right;
    }
    return root;
}
BST *findMin(BST *root){
    if(!root) return root;
    while(!root->left)
        root = root->left;
    return root;
}

BST *insert(BST *root,int data){
    if(!root){
        BST *node = new BST(data);
        if(!node){
            cout<<"Memory Error!";
        }else{
            root = node;
        }
    }else{
        if(root->data > data){
            root->left = insert(root->left,data);
        }else{
            root->right = insert(root->right,data);
        }
    }
    return root;
}

BST *deleteNode(BST *root,int data){
    BST *temp;
    if(!root){
        cout<<"Element not there in tree!";
    }else if(data < root->data){
        root->left = deleteNode(root->left,data);
    }else if(data > root->data){
        root->right = deleteNode(root->right,data);
    }else{
        // found element
        if(root->right && root->left){
            temp = findMax(root->left);
            root->data = temp->data;
            root->left = deleteNode(root->left,root->data);
        }else{
            // one child
            temp = root;
            if(!root->left) root = root->right;
            if(!root->right) root = root->left;
            delete temp;
        }
    }
    return root;
}

void inorder(BST *root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    BST *head = NULL;
    head = insert(head,9);
    head = insert(head,14);
    head = insert(head,2);
    head = insert(head,7);
    head = insert(head,8);
    head = insert(head,5);
    head = insert(head,6);
    head = insert(head,3);
    head = insert(head,4);
    head = insert(head,10);
    head = insert(head,11);
    head = insert(head,40);
    head = insert(head,0);
    head = insert(head,12);
    head = insert(head,15);
    
    head = deleteNode(head,4);
    inorder(head);
    return 0;
}
