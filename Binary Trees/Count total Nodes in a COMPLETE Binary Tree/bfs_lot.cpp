class Solution {
    public:
        int countNodes(TreeNode* root) {
            if(!root) return {};
            queue<TreeNode*> Q;
            Q.push(root);
            int count = 0;
            while(!Q.empty()){
                int size = Q.size();
                count += size;
                for(int i=0; i<size; i++){
                    TreeNode* curNode = Q.front();
                    Q.pop();
                    if(curNode->left)
                        Q.push(curNode->left);
                    if(curNode->right)
                        Q.push(curNode->right);
                }
            }
            return count;
        }
    };