class tabulation {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int m = obstacleGrid.length, n = obstacleGrid[0].length;
        
        // if Start or End = obstacle
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        
        int[] above = new int[n];
        above[0] = 1;  
        
        for (int row = 0; row < m; row++) {
            int[] current = new int[n];
            for (int col = 0; col < n; col++) {
                if (obstacleGrid[row][col] == 1) {
                    current[col] = 0; // Obstacle 
                } else {
                    if (col == 0 && row == 0) {
                        current[col] = 1; 
                    } else {
                        if (col > 0) {
                            current[col] += current[col - 1];
                        }
                        if (row > 0) {
                            current[col] += above[col];
                        }
                    }
                }
            }
            above = current;
        }
        
        return above[n - 1];
    }
}
