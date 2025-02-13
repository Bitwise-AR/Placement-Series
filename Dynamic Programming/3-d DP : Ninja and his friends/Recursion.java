class Solution {
    public int solve(int n, int m, int[][] grid) {
        return collectChocolates(grid, 0, 0, m - 1, n, m);
    }

    private int collectChocolates(int[][] grid, int i, int j1, int j2, int n, int m) {
        if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) {
            return Integer.MIN_VALUE;
        }

        if (i == n - 1) {
            if (j1 == j2) return grid[i][j1];  
            else return grid[i][j1] + grid[i][j2]; 
        }

        int maxChocolates = Integer.MIN_VALUE;
        for (int move1 = -1; move1 <= 1; move1++) {  
            for (int move2 = -1; move2 <= 1; move2++) {  
                int newJ1 = j1 + move1;
                int newJ2 = j2 + move2;
                int currentChocolates = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

                int chocolates = currentChocolates + collectChocolates(grid, i + 1, newJ1, newJ2, n, m);
                maxChocolates = Math.max(maxChocolates, chocolates);
            }
        }

        return maxChocolates;
    }
}