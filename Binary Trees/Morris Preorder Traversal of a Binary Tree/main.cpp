class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) { // Morris Preorder
            vector<int> ans;
            TreeNode* curr = root;
    
            while(curr != NULL){
                if(curr -> left == NULL){
                    ans.push_back(curr -> val);
                    curr = curr -> right;
                }
                else{
                    TreeNode* prev = curr -> left;
    
                    while(prev -> right != NULL && prev -> right != curr){
                        prev =prev -> right;
                    }
    
                    if(prev -> right == NULL){
                        ans.push_back(curr-> val);
                        prev -> right = curr;
                        curr = curr -> left;
                    }
                    else{
                        prev -> right = NULL;
                        curr = curr -> right;
                    }
                }
            }
    
            return ans;
        }
    };