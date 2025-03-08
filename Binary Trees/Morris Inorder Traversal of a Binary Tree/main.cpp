class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) { //Morris Inorder
            vector<int> ans;
            TreeNode* cur = root;
    
            while(cur != NULL){
                if(cur->left == NULL){
                    ans.push_back(cur->val);
                    cur = cur->right;
                }
                else{
                    TreeNode* leftChild = cur->left;
                    while(leftChild->right != NULL){
                        leftChild = leftChild->right;
                    }
                    leftChild->right = cur;
                    
                    TreeNode* temp = cur;
                    cur = cur->left;
                    temp->left = NULL;
                }
            }
    
            return ans;
        }
    };