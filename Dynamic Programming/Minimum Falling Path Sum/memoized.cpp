class Solution {
    public:
        int n;
        int dp[101][101];
        int solve(int row, int col, vector<vector<int>>& matrix) {
            if(row > n-1 || col > n-1 || col < 0)
                return 1e9;
    
            if(row == n-1){
                return matrix[row][col];
            }
    
            if(dp[row][col] != -1)
                return dp[row][col];
    
            int left_diag  = matrix[row][col] + solve(row+1, col-1, matrix);
            int down       = matrix[row][col] + solve(row+1, col, matrix);
            int right_diag = matrix[row][col] + solve(row+1, col+1, matrix);
    
            return dp[row][col] = min({left_diag, right_diag, down});
        }
    
        int minFallingPathSum(vector<vector<int>>& matrix) {
            n = matrix.size();
            int result = 1e9;
            memset(dp, -1, sizeof(dp));
            
            for(int col=0; col<n; col++){
                result = min(result, solve(0, col, matrix));
            }
    
            return result;
        }
    };