class Solution {
    public:
      vector<vector<int>> ans;
      
      bool isLeaf(Node* root){
          return (root->left == NULL && root->right == NULL);
      }
      
      void solve(Node* root, vector<int> &temp){
          if(root == NULL)
              return;
          
          temp.push_back(root->data);
          
          if(isLeaf(root))
              ans.push_back(temp);
          
          solve(root->left, temp);
          solve(root->right, temp);
          
          temp.pop_back();
      }
      
      vector<vector<int>> Paths(Node* root) {
          if(!root) return {};
          vector<int> temp;
          solve(root, temp);
          return ans;
      }
  };