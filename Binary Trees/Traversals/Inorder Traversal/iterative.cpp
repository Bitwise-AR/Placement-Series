class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            if(root == nullptr) return {};
            vector<int> ans;
            stack<TreeNode*> st;
            TreeNode* currentNode = root;
            while(true) {
                if(currentNode != nullptr){
                    st.push(currentNode);
                    currentNode = currentNode->left;
                }
                else{
                    if(st.empty()) break;
                    currentNode = st.top();
                    st.pop();
                    ans.push_back(currentNode->val);
                    currentNode = currentNode->right;
                }
            }
            return ans;
        }
    };