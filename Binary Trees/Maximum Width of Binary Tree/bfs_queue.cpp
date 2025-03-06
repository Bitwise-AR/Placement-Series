class Solution {
    public:
        typedef unsigned long long ll;
        
        int widthOfBinaryTree(TreeNode* root) {
            queue<pair<TreeNode*, ll>> Q;
            Q.push({root, 0});
            ll maxWidth = 0;
            
            while(!Q.empty()){
                int size = Q.size();
                ll L = Q.front().second;
                ll R = Q.back().second;
                ll curWidth = R-L + 1;
                maxWidth = max(maxWidth, curWidth);

                for(int i=0; i<size; i++){
                    TreeNode* curNode = Q.front().first;
                    ll idx = Q.front().second;
                    Q.pop();
    
                    if(curNode->left)
                        Q.push({curNode->left, 2*idx+1});
                    if(curNode->right)
                        Q.push({curNode->right, 2*idx+2});
                }
            }
            return maxWidth;
        }
    };