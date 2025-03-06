class Solution {
    public:
        bool solve(TreeNode* A, TreeNode* B) {
            if(A == NULL && B == NULL) return true;
            if(A == NULL || B == NULL) return false;
            if(A->val != B->val) return false;
    
            bool left = solve(A->left, B->right);
            bool right = solve(A->right, B->left);
    
            return (left && right);
        }
    
        bool isSymmetric(TreeNode* root) {
            return solve(root, root);
        }
    };