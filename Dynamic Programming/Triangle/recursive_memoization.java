import java.util.*;

public class recursive_memoization {
    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.size();
        int[][] dp = new int[n][n];

        for(int[] row : dp)
        {
            Arrays.fill(row , -1);
        }

        return helper(0,0,triangle,dp,n);
    }
    private static int helper(int i, int j, List<List<Integer>> num, int[][] dp, int n) {
        if(dp[i][j] != -1) return dp[i][j];

        if(i==n-1) return num.get(i).get(j);

        int down = num.get(i).get(j) + helper(i+1,j,num,dp,n);
        int diagonal = num.get(i).get(j) + helper(i+1,j+1,num,dp,n);

        return dp[i][j] = Math.min(down,diagonal);    
    }
}
