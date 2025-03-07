class Solution {
    public:
      unordered_map<Node*, Node*> parentOf;
      
      Node* createParentMapping(Node* root, int target){
          queue<Node*> Q;
          Q.push(root);
          
          parentOf[root] = NULL;
          
          Node* targetNode = NULL;
          
          while(!Q.empty()){
              Node* curNode = Q.front();
              Q.pop();
              
              if(curNode->data == target)
                  targetNode = curNode;
              
              if(curNode->left){
                  Q.push(curNode->left);
                  parentOf[curNode->left] = curNode;
              }
              
              if(curNode->right){
                  Q.push(curNode->right);
                  parentOf[curNode->right] = curNode;
              }
              
          }
          return targetNode;
      }
      
      int solve(Node* targetNode){
          queue<Node*> Q;
          Q.push(targetNode);
          
          unordered_map<Node*, bool> visited;
          visited[targetNode] = true;
          
          int ans = 0;
          
          while(!Q.empty()){
              
              int size = Q.size();
              bool flag = 0;
              
              for(int i=0; i<size; i++){
                  Node* curNode = Q.front();
                  Q.pop();
                  
                  if(curNode->left && !visited[curNode->left]){
                      flag = 1;
                      Q.push(curNode->left);
                      visited[curNode->left] = true;
                  }
                  
                  if(curNode->right && !visited[curNode->right]){
                      flag = 1;
                      Q.push(curNode->right);
                      visited[curNode->right] = true;
                  }
                  
                  if(parentOf[curNode] && !visited[parentOf[curNode]]){
                      flag = 1;
                      Q.push(parentOf[curNode]);
                      visited[parentOf[curNode]] = true;
                  }
              }
              
              if(flag == 1) ans++;
          }
          
          return ans;
      }
      
      int minTime(Node* root, int target) {
          Node* targetNode = createParentMapping(root, target);
          int ans = solve(targetNode);
          return ans;
      }
  };