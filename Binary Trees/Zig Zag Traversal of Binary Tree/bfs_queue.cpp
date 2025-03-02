class Solution {
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            if(!root) return {};
            
            vector<vector<int>> ans;
            queue<TreeNode*> Q;
            Q.push(root);
            
            while(!Q.empty()){
                int size = Q.size();
                vector<int> curLevel;
                for(int i=0; i<size; i++){
                    TreeNode* curNode = Q.front();
                    Q.pop();
                    curLevel.push_back(curNode->val);
                    if(curNode->left) Q.push(curNode->left);
                    if(curNode->right) Q.push(curNode->right);
                }
                ans.push_back(curLevel);
            }
    
            for(int i=1; i<ans.size(); i+=2){
                reverse(ans[i].begin(), ans[i].end());
            }
    
            return ans;
        }
    };