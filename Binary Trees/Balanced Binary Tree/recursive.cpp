class Solution {
    public:
        int checkBalance(TreeNode* root) {
            if (root == NULL) return 0;
    
            int left = checkBalance(root->left);
            if(left == -1) return -1;
    
            int right = checkBalance(root->right);
            if(right == -1) return -1;
    
            if (abs(left - right) > 1) return -1;
    
            return 1 + max(left, right);
        }
    
        bool isBalanced(TreeNode* root) {
            return checkBalance(root) != -1;
        }
    };