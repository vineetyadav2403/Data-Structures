#include <bits/stdc++.h>
using namespace std;
 
// Node structure
struct Node {
    // Data of the node
    int data;
 
    // Horizontal Distance of the node
    int hd;
 
    // Reference to left node
    struct Node* left;
 
    // Reference to right node
    struct Node* right;
};
 
// Initialising node
struct Node* newNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->hd = INT_MAX;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
void printTopViewUtil(Node* root, int height,
    int hd, map<int, pair<int, int> >& m)
{
    // Base Case
    if (root == NULL)
        return;
 
    // If the node for particular horizontal distance
    // is not present in the map, add it.
    // For top view, we consider the first element 
    // at horizontal distance in level order traversal
    if (m.find(hd) == m.end()) {
        m[hd] = make_pair(root->data, height);
    }
    else{
        pair<int, int> p = (m.find(hd))->second;
                 
        if (p.second > height) {
            m.erase(hd);
            m[hd] = make_pair(root->data, height);
        }
    }
 
    // Recur for left and right subtree
    printTopViewUtil(root->left, height + 1, hd - 1, m);
    printTopViewUtil(root->right, height + 1, hd + 1, m);
}
 
void printTopView(Node* root)
{
    // Map to store horizontal distance, 
    // height and node's data
    map<int, pair<int, int> > m;
    printTopViewUtil(root, 0, 0, m);
 
    // Print the node's value stored by printTopViewUtil()
    for (map<int, pair<int, int> >::iterator it = m.begin(); 
                                        it != m.end(); it++) {
        pair<int, int> p = it->second;
        cout << p.first << " ";
    }
}
 
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);
 
    cout << "Top View : ";
    printTopView(root);
 
    return 0;
}
