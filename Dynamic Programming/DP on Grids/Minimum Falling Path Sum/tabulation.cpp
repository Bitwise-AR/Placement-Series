class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
            int dp[n][n];
            
            //initializing first row of dp-array = first row of matrix-array
            for(int col=0; col<n; col++){
                dp[0][col] = matrix[0][col];
            }
    
            for(int row=1; row<n; row++){
                for(int col=0; col<n; col++){
                    int a = dp[row-1][col]; //from above
                    int b = (col>0) ? dp[row-1][col-1] : INT_MAX; //top-left diag
                    int c = (col<n-1) ? dp[row-1][col+1] : INT_MAX; //top-right diag
    
                    dp[row][col] = matrix[row][col] + min({a, b, c});
                }
            }
    
            //finding the minimum value from the last row of dp-array
            int ans = INT_MAX;
            for(int col=0; col<n; col++){
                ans = min(ans, dp[n-1][col]);
            }
    
            return ans;
        }
    };