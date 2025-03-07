class Solution {
    public:
        unordered_map<TreeNode*, TreeNode*> parentOf;
        vector<int> ans;
    
        void inorder(TreeNode* root){
            if(!root) return;
            
            if(root->left)
                parentOf[root->left] = root;
            inorder(root->left);
    
            if(root->right)
                parentOf[root->right] = root;
            inorder(root->right);
        }
    
        void solve(TreeNode* target, int k){
            queue<TreeNode*> Q;
            Q.push(target);
    
            unordered_set<int> visited;
            visited.insert(target->val);
    
            while(!Q.empty()){
                int size = Q.size();
                if(k == 0) break;
                for(int i=0; i<size; i++){
                    TreeNode* curNode = Q.front();
                    Q.pop();
    
                    if(curNode->left && !visited.count(curNode->left->val)){
                        Q.push(curNode->left);
                        visited.insert(curNode->left->val);
                    }
                    
                    if(curNode->right && !visited.count(curNode->right->val)){
                        Q.push(curNode->right);
                        visited.insert(curNode->right->val);
                    }
                    
                    if(parentOf.count(curNode) && !visited.count(parentOf[curNode]->val)){
                        Q.push(parentOf[curNode]);
                        visited.insert(parentOf[curNode]->val);
                    }
                }
                k--;
            }
    
            while(!Q.empty()){
                ans.push_back(Q.front()->val);
                Q.pop();
            }
        }
    
        vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
            inorder(root);
            solve(target, k);
            return ans;
        }
    };