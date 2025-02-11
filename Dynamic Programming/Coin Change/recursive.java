public class recursive {
    public int helper(int[] coins, int amount) {
        if (amount == 0) return 0;

        int res = (int) 1e9;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = Math.min(res, 1 + helper(coins, amount - coin));
            }
        }
        return res;
    }

    public int coinChange(int[] coins, int amount) {
        int minCoins = helper(coins, amount);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
}