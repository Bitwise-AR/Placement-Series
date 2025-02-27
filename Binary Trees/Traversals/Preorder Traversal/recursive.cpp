class Solution {
    public:
        vector<int> ans;
        vector<int> preorderTraversal(TreeNode* root) {
            if(root == nullptr) return ans;
            ans.push_back(root->val);
            preorderTraversal(root->left);
            preorderTraversal(root->right);
            return ans;
        }
    };