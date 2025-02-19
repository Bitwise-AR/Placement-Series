import java.util.Arrays;

class memoization {
    
    private int helper(int n, int capacity, int val[], int wt[], int i, int[][] dp){
        if(i >= n) return 0;
        if(capacity <= 0) return 0;
        
        if(dp[i][capacity] != -1){
            return dp[i][capacity];
        }
        
        int take = 0;
        int notTake = helper(n, capacity, val, wt, i+1, dp);
        
        if(capacity - wt[i] >= 0){
            take = val[i] + helper(n, capacity-wt[i], val, wt, i, dp);
        }
        
        dp[i][capacity] = Math.max(take, notTake);
        return dp[i][capacity];
    }
    
    public int knapSack(int val[], int wt[], int capacity) {
        int n = val.length;
        int[][] dp = new int[n+1][capacity+1];
        
        for (int[] r : dp) {
            Arrays.fill(r, -1);
        }
        
        int res = helper(n, capacity, val, wt, 0, dp);
        return res;
    }
}

