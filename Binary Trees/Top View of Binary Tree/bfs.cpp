class Solution {
    public:
      vector<int> topView(Node *root) {
          if(!root) return {};
          
          vector<int> ans;
          queue<pair<Node*, int>> Q;
          //Queue storing -> pair of -> {cur_node, col_position}
          Q.push({root, 0});
          
          map<int, int> mp;
          
          while(!Q.empty()){
              Node* curNode = Q.front().first;
              int col = Q.front().second;
              Q.pop();
              
              //if the key 'col' does not exist in the map 'mp'
              if(mp.find(col) == mp.end())
                  mp[col] = curNode->data;
              
              if(curNode->left) 
                  Q.push({curNode->left, col-1});
              if(curNode->right)
                  Q.push({curNode->right, col+1});
          }
          
          for(auto& it : mp) {
              ans.push_back(it.second);
          }
          
          return ans;
      }
  };