class Solution {
  public:
    unordered_map<Node*, Node*> parent;
    
    void preorder(Node* cur, Node* par) {
        if(!cur) return;
        
        parent[cur] = par;
        preorder(cur->left, cur);
        preorder(cur->right, cur);
    }
    
    Node* findNode(Node* root, int target) {
        if(!root) return NULL;
        if(root->data == target) return root;
        
        Node* left = findNode(root->left, target);
        if(left) return left;
        
        return findNode(root->right, target);
    }
    
    int minTime(Node* root, int target) {
        preorder(root, NULL);
        Node* targetNode = findNode(root, target);
        
        queue<Node*> q;
        q.push(targetNode);
        
        unordered_set<Node*> visited;
        visited.insert(targetNode);
        int count = -1;
        
        while(!q.empty()) {
            int size = q.size();
            count += 1;
            
            for(int i=0; i<size; ++i){
                Node* cur = q.front();
                q.pop();
                
                if(cur->left && !visited.count(cur->left)){
                    visited.insert(cur->left);
                    q.push(cur->left);
                }
                
                if(cur->right && !visited.count(cur->right)){
                    visited.insert(cur->right);
                    q.push(cur->right);
                }
                
                if(parent[cur] && !visited.count(parent[cur])){
                    visited.insert(parent[cur]);
                    q.push(parent[cur]);
                }
            }
        }
        
        return count;
    }
};