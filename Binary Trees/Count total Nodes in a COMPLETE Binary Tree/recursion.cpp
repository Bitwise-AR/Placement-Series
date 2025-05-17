class Solution {
public:
    int getLeftHt(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int getRightHt(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }

    int countNodes(TreeNode* root) {
        if (!root) return 0;

        int leftSubtreeHt = getLeftHt(root);
        int rightSubtreeHt = getRightHt(root);

        // if its a complete BT: no. of node = 2^h - 1
        if (leftSubtreeHt == rightSubtreeHt) {
            return (1 << leftSubtreeHt) - 1;
        }

        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};