class Solution {
    public int solve(int n, int m, int[][] grid) {
        int[][][] dp = new int[n][m][m]; 
        for (int[][] row : dp) {
            for (int[] col : row) {
                Arrays.fill(col, -1);
            }
        }
        return robot(grid, 0, 0, m - 1, n, m, dp);
    }

    public int robot(int[][] grid, int i, int j1, int j2, int n, int m, int[][][] dp) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return Integer.MIN_VALUE;
        }

        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1]; 
            else return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxChocolates = Integer.MIN_VALUE;

        for (int dj1 = -1; dj1 <= 1; dj1++) {  
            for (int dj2 = -1; dj2 <= 1; dj2++) {  
                int nextJ1 = j1 + dj1;
                int nextJ2 = j2 + dj2;
                int currentChocolates = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                maxChocolates = Math.max(maxChocolates, currentChocolates + robot(grid, i + 1, nextJ1, nextJ2, n, m, dp));
            }
        }

        return dp[i][j1][j2] = maxChocolates;
    }
}