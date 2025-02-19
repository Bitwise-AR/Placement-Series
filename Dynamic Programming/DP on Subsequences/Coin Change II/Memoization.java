import java.util.Arrays;

class Solution {
    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length][amount + 1];

        for (int[] row : dp){
            Arrays.fill(row, -1);
        }
        
        return helper(coins, amount, 0, dp);
    }

    public int helper(int[] coins, int amount, int index, int[][] dp) {
        if(amount == 0) return 1;  
        if(amount < 0 || index >= coins.length) return 0; 

        if(dp[index][amount] != -1){
            return dp[index][amount];
        }

        int take = 0;
        if(amount >= coins[index]){
            take = helper(coins, amount - coins[index], index, dp); 
        }

        int skip = helper(coins, amount, index + 1, dp); 

        return dp[index][amount] = take + skip;
    }
}