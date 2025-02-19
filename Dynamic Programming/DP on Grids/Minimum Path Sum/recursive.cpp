class Solution {
    public:
        int m, n;
        int solve(int row, int col, vector<vector<int>>& grid) {
            if(row > m-1 || col > n-1)
                return 1e9;
    
            if(row == m-1 && col == n-1){
                return grid[row][col];
            }
    
            int right = grid[row][col] + solve(row, col+1, grid);
            int down  = grid[row][col] + solve(row+1, col, grid);
    
            return min(right, down);
        }
    
        int minPathSum(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size();
            return solve(0, 0, grid);
        }
    };