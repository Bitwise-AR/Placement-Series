class Solution{
    public:
    int solve(Node* root) {
        if(!root || (root->left == NULL && root->right == NULL)) 
            return 1;
        
        int left=0, right=0;
        
        if(root->left)
            left  = root->left->data;
        if(root->right)
            right = root->right->data;
        
        if(root->data == (left + right) && solve(root->left) && solve(root->right))
            return 1;
        else
            return 0;
    }
    
    int isSumProperty(Node *root)
    {
        return solve(root);
    }
};