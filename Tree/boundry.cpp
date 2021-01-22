/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List leftBoundary;
    List leaves;
    List rightBoundary;
    public List boundaryOfBinaryTree(TreeNode root) {
        List res = new ArrayList<>();
        if (root == null) {
            return res;
        }
        leftBoundary = new ArrayList<>();
        leaves = new ArrayList<>();
        rightBoundary = new ArrayList<>();
        
        res.add(root.val);
        preorder(root.left, true, false);
        preorder(root.right, false, true);
        
        res.addAll(leftBoundary);
        res.addAll(leaves);
        Collections.reverse(rightBoundary); // important
        res.addAll(rightBoundary);
        
        return res;
    }
    
    private void preorder(TreeNode node, boolean isLeftBoundary, boolean isRightBoundary) {
        if (node != null) {
             if (isLeftBoundary) {
                leftBoundary.add(node.val);
            } 
            else if (isRightBoundary) {
                rightBoundary.add(node.val);
            }
            else if (node.left == null && node.right == null) {
                leaves.add(node.val);
            } 
            
            // left child    
            preorder(node.left, isLeftBoundary, isRightBoundary && node.right == null);
            // right child
            preorder(node.right, isLeftBoundary && node.left == null, isRightBoundary);
        }
    }
}
