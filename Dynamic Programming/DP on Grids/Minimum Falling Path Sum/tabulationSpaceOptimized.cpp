class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size();
    
            for(int row=1; row<n; row++){
                for(int col=0; col<n; col++){
                    int a = matrix[row-1][col]; //from above
                    int b = (col>0) ? matrix[row-1][col-1] : INT_MAX; //top-left diag
                    int c = (col<n-1) ? matrix[row-1][col+1] : INT_MAX; //top-right diag
    
                    matrix[row][col] = matrix[row][col] + min({a, b, c});
                }
            }
    
            //finding the minimum value from the last row
            int ans = INT_MAX;
            for(int col=0; col<n; col++){
                ans = min(ans, matrix[n-1][col]);
            }
    
            return ans;
        }
    };