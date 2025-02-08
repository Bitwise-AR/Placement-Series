import java.util.*;
class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        int[][] dp = new int[m][n];

        for(int[] row : dp){
            Arrays.fill(row, -1);
        }

        return recur(m, n, 0, 0, grid, dp);
    }

    public int recur(int m, int n, int i, int j, int[][] grid, int[][] dp){
        //base case 
        if(i == m-1 && j == n-1){
            return dp[i][j] = grid[i][j];
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(i == m-1){
            return dp[i][j] = recur(m,n,i,j+1,grid,dp) + grid[i][j];
        }

        if(j == n-1){
            return dp[i][j] = recur(m,n,i+1,j,grid,dp) + grid[i][j];
        }

            int right = recur(m,n,i,j+1,grid,dp) + grid[i][j];
            int down = recur(m,n,i+1,j,grid,dp) + grid[i][j];
            dp[i][j] = Math.min(right, down);

        return dp[i][j];
    }
}