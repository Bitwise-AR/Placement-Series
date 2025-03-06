class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            if(!root) return {};
    
            vector<int> ans;
            queue<TreeNode*> Q;
            Q.push(root);
    
            while(!Q.empty()){
                int size = Q.size();
                for(int i=0; i<size; i++){
                    TreeNode* node = Q.front();
                    Q.pop();
                    
                    //add only if, node is the right most in Level Order Traversal
                    if(i == size-1)
                        ans.push_back(node->val);
    
                    if(node->left)
                        Q.push(node->left);
    
                    if(node->right)
                        Q.push(node->right);
                }
            }
    
            return ans;
        }
    };