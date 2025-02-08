class Solution {
    public int minPathSum(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        return recur(m, n, 0, 0, grid);
    }

    public int recur(int m, int n, int i, int j, int[][] grid){
        //base case 
        if(i == m-1 && j == n-1){
            return grid[i][j];
        }

        if(i == m-1){
            return recur(m,n,i,j+1,grid) + grid[i][j];
        }

        if(j == n-1){
            return recur(m,n,i+1,j,grid) + grid[i][j];
        }

            int minm = Integer.MAX_VALUE;
            int right = recur(m,n,i,j+1,grid) + grid[i][j];
            int down = recur(m,n,i+1,j,grid) + grid[i][j];
            minm = Math.min(right, down);

        return minm;
    }
}