class Solution {
    public:
        map<int, map<int, multiset<int>>> mp;
        void solve(TreeNode* root, int col, int row) {
            if(root == NULL)
                return;
            
            mp[col][row].insert(root->val);
            solve(root->left, col-1, row+1);
            solve(root->right, col+1, row+1);
        }
    
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            solve(root, 0, 0);
            vector<vector<int>> ans;
    
            // map[col, row -> multiset()]
            for(auto& col_val : mp){
                vector<int> vertical_line;
                for(auto& row_val : col_val.second){
                    for(auto& val : row_val.second){
                        vertical_line.push_back(val);
                    }
                }
                ans.push_back(vertical_line);
            }
    
            return ans;
        }
    };