class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n = triangle.size();
            int dp[n][n];
    
            for(int col=0; col<n; col++){
                dp[n-1][col] = triangle[n-1][col];
            }
    
            for(int row=n-2; row>=0; row--){
                for(int col=row; col>=0; col--){
                    int down = triangle[row][col] + dp[row+1][col];
                    int diag = triangle[row][col] + dp[row+1][col+1];
                    dp[row][col] = min(down, diag);
                }
            }
            
            return dp[0][0];  
        }
    };