import java.util.*;

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
    public boolean isSymmetric(TreeNode root) {
        if(root == null) return true;
        
        Queue<TreeNode> q = new LinkedList<>();

        q.add(root.left);
        q.add(root.right);

        while(!q.isEmpty()) {
            TreeNode leftTree = q.poll();
            TreeNode rightTree = q.poll();
            
            if(leftTree == null && rightTree == null) {
                continue;
            }

            if(leftTree == null || rightTree == null) {
                return false;
            }

            if(leftTree.val != rightTree.val) {
                return false;
            }

            q.add(leftTree.left);
            q.add(rightTree.right);
            q.add(leftTree.right);
            q.add(rightTree.left);
        }
        
        return true;
    }
}