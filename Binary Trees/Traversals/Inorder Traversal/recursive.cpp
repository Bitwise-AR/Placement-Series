class Solution {
    public:
        vector<int> ans;
        vector<int> inorderTraversal(TreeNode* root) {
            if(root == nullptr) return ans;
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->right);
            return ans;
        }
    };