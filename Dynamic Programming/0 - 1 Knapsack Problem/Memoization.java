

class Solution {
    static int knapSack(int capacity, int val[], int wt[]) {
        // code here
        int n = val.length;
        int[][] dp = new int[n][capacity + 1];
        for(int[] row: dp){
            for(int i=0;i<row.length;i++){
                row[i] = -1;
            }
        }
        return recur(capacity, val, wt, 0,n, dp);
    }
    
    public static int recur(int capacity, int[] val, int[] wt, int ind, int n, int[][] dp) {
        if(capacity == 0 || ind == n){
            return 0;
        }
        
        if(dp[ind][capacity] != -1){
            return dp[ind][capacity];
        }
        
        int take = Integer.MIN_VALUE;
        if(wt[ind] <= capacity){
            take = val[ind] + recur(capacity - wt[ind], val, wt, ind + 1,n, dp);
        }
        
        int notTake = 0 + recur(capacity, val, wt, ind + 1,n, dp);
        
        return dp[ind][capacity] = Math.max(take, notTake);
    }
}