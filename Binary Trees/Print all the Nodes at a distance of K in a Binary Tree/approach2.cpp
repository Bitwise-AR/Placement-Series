class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void preorder(TreeNode* cur, TreeNode* par){
        if(!cur) return;

        parent[cur] = par;
        preorder(cur->left, cur);
        preorder(cur->right, cur);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        preorder(root, NULL);
        
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;

        while(!q.empty()) {
            int size = q.size();
            if(k==0) break;

            for(int i=0; i<size; i++){
                TreeNode* cur = q.front();
                q.pop();

                visited.insert(cur);

                if(cur->left  && !visited.count(cur->left))
                    q.push(cur->left);
                if(cur->right && !visited.count(cur->right))
                    q.push(cur->right);
                if(parent[cur] && !visited.count(parent[cur]))
                    q.push(parent[cur]);
            }
            k--;
        }

        vector<int> ans;
        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();
            ans.push_back(cur->val);
        }

        return ans;
    }
};