vector<int> preorderTraversal(TreeNode* root) {
    if(root == nullptr) return {};
    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* currentNode = st.top();
        st.pop();
        ans.push_back(currentNode->val);
        if(currentNode->right != nullptr) st.push(currentNode->right);
        if(currentNode->left != nullptr) st.push(currentNode->left);
    }
    return ans;
}