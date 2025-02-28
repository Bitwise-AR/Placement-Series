class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if(root == nullptr) return 0;
            int count = 0;
            queue<TreeNode*> Q;
            Q.push(root);
            while(!Q.empty()){
                int size = Q.size();
                while(size--){
                    TreeNode* currentNode = Q.front();
                    if(currentNode->left != nullptr) Q.push(currentNode->left);
                    if(currentNode->right != nullptr) Q.push(currentNode->right);
                    Q.pop();
                }
                count += 1;
            }
            return count;
        }
    };