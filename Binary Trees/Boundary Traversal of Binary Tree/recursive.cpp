class Solution {
    public:
      bool isLeaf(Node* root){
          return (root->left == NULL && root->right == NULL);
      }
      
      void addLeft(Node* root, vector<int> &ans){
          Node* cur = root->left;
          while(cur){
              if(!isLeaf(cur))
                  ans.push_back(cur->data);
              if(cur->left)
                  cur = cur->left;
              else
                  cur = cur->right;
          }
      }
      
      void addRight(Node* root, vector<int> &ans){
          Node* cur = root->right;
          stack<int> st;
          
          while(cur){
              if(!isLeaf(cur))
                  st.push(cur->data);
              if(cur->right)
                  cur = cur->right;
              else
                  cur = cur->left;
          }
          
          while(!st.empty()){
              ans.push_back(st.top());
              st.pop();
          }
      }
      
      void addLeaf(Node* root, vector<int> &ans){
          if(isLeaf(root)){
              ans.push_back(root->data);
              return;
          }
          
          if(root->left)
              addLeaf(root->left, ans);
          if(root->right)
              addLeaf(root->right, ans);
      }
      
      vector<int> boundaryTraversal(Node *root) {
          if(!root) return {};
          vector<int> ans;
          if(!isLeaf(root))
              ans.push_back(root->data);
          
          addLeft(root, ans);
          addLeaf(root, ans);
          addRight(root, ans);
          
          return ans;
      }
  };