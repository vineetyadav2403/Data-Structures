https://leetcode.com/problems/path-sum-iii/

// O(n^2)-----------------------------------

int total = 0;
    void findPath(TreeNode *root,int &sum, int curr){
        if(!root) return;
        curr+=root->val;
        if(curr==sum)
            total++;
        findPath(root->left,sum,curr);
        findPath(root->right,sum,curr);
    }
    
    
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        findPath(root,sum,0);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        
        return total;
    }


//O(n)--------------
