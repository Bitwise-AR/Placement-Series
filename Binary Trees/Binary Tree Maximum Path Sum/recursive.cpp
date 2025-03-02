class Solution {
    public:
        int maxSum = INT_MIN;
        
        int solve(TreeNode* root) {
            if(root == NULL) return 0;
    
            int left = max(0, solve(root->left)); //ignoring neg values
            int right = max(0, solve(root->right));
    
            maxSum = max(maxSum, root->val + left + right);
    
            return root->val + max(left, right);
        }
    
        int maxPathSum(TreeNode* root) {
            solve(root);
            return maxSum;
        }
    };