import java.util.Arrays;

class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][] dp = new int[n][2];  

        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return helper(prices, 0, 0, dp);
    }

    public int helper(int[] prices, int i, int factor, int[][] dp) {
        if (i == prices.length) {
            return 0;
        }

        if (dp[i][factor] != -1) {
            return dp[i][factor];
        }

        int profit;
        if (factor == 0) {
            int buy = -prices[i] + helper(prices, i + 1, 1, dp);
            int notBuy = helper(prices, i + 1, 0, dp);
            profit = Math.max(buy, notBuy);
        } else {
            int sell = prices[i] + helper(prices, i + 1, 0, dp);
            int notSell = helper(prices, i + 1, 1, dp);
            profit = Math.max(sell, notSell);
        }

        return dp[i][factor] = profit;
    }
}