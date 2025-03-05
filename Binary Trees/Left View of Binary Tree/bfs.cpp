class Solution {
    public:
      vector<int> leftView(Node *root) {
          if(!root) return {};
  
          vector<int> ans;
          queue<Node*> Q;
          Q.push(root);
  
          while(!Q.empty()){
              int size = Q.size();
              for(int i=0; i<size; i++){
                  Node* node = Q.front();
                  Q.pop();

                  //add only if, node is the left most in Level Order Traversal
                  if(i == 0)
                      ans.push_back(node->data);
  
                  if(node->left)
                      Q.push(node->left);
  
                  if(node->right)
                      Q.push(node->right);
              }
          }
          return ans;
      }
  };