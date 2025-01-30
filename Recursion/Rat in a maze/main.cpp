class Solution {
  public:
    int n;
    
    void solve(int i, int j, string &temp, vector<vector<int>> &mat, vector<string> &ans){
        if(i>=n-1 && j>=n-1){
            ans.push_back(temp);
            return;
        }
        
        if(i<0 || j<0 || i>=n || j>=n || mat[i][j] != 1)
            return;
        
        mat[i][j] = 0;
        
        temp.push_back('D');
        solve(i+1, j, temp, mat, ans);
        temp.pop_back();
        
        temp.push_back('R');
        solve(i, j+1, temp, mat, ans);
        temp.pop_back();
        
        temp.push_back('L');
        solve(i, j-1, temp, mat, ans);
        temp.pop_back();
        
        temp.push_back('U');
        solve(i-1, j, temp, mat, ans);
        temp.pop_back();
        
        mat[i][j] = 1;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        n = mat.size();
        vector<string> ans;
        string temp = "";
        solve(0, 0, temp, mat, ans);
        return ans;
    }
};