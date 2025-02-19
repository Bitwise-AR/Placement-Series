import java.util.*;

class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int[][][] dp = new int[n][2][k+1];
        for(int[][] grid : dp){
            for(int[] row : grid){
                Arrays.fill(row,-1);
            }
        }

        return helper(prices,0,0,k,dp);
    }

    public int helper(int[] prices, int i,int factor, int curr, int[][][] dp){
        if(i == prices.length || curr == 0){
            return 0;
        }

        if(dp[i][factor][curr] != -1){
            return dp[i][factor][curr];
        }

        int maxVal = Integer.MIN_VALUE;
        if(factor == 0){
            int buy = -prices[i] + helper(prices, i + 1,1,curr,dp);
            int notBuy = 0 + helper(prices, i+1,0,curr,dp);
            maxVal = Math.max(buy, notBuy);
        }else{
            int sell = prices[i] + helper(prices, i + 1,0,curr - 1, dp);
            int notSell = 0 + helper(prices,i+1,1,curr,dp);
            maxVal = Math.max(sell, notSell);
        }

        return dp[i][factor][curr] = maxVal;
    }
}