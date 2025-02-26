class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {
            if(root == nullptr) return {};
            vector<vector<int>> ans;
            queue<TreeNode*> Q;
            Q.push(root);
            while(!Q.empty()){
                int size = Q.size();
                vector<int> currentLevel;
                while(size-- > 0){
                    TreeNode* currentNode = Q.front();
                    currentLevel.push_back(currentNode->val);
                    if(currentNode->left != nullptr) Q.push(currentNode->left);
                    if(currentNode->right != nullptr) Q.push(currentNode->right);
                    Q.pop();
                }
                ans.push_back(currentLevel);
            }
            return ans;
        }
    };