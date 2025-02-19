class Solution {
    public:
        int m, n;
        int solve(int row, int col, vector<vector<int>> &obstacleGrid){
            if(row < m && col <  n && obstacleGrid[row][col] == 1)
                return 0;
            
            if(row == m-1 && col == n-1)
                return 1;
            
            if(row >= m || col >= n)
                return 0;
            
    
            int down = solve(row+1, col, obstacleGrid);
            int right = solve(row, col+1, obstacleGrid);
    
            return down + right;
    
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            m = obstacleGrid.size();
            n = obstacleGrid[0].size();
    
            return solve(0, 0, obstacleGrid);
        }
    };