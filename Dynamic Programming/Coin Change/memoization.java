public class memoization {
    public int helper(int[] coins, int amount, int[] dp) {
        if (amount == 0) return 0;
        if (amount < 0) return (int) 1e9;

        if (dp[amount] != -1) return dp[amount];

        int res = (int) 1e9;
        
        for (int coin : coins) {
            res = Math.min(res, 1 + helper(coins, amount - coin, dp));
        }
        
        return dp[amount] = res;
    }

    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, -1);
        
        int minCoins = helper(coins, amount, dp);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
}
