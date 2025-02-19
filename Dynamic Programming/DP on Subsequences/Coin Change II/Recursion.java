class Solution {
    public int change(int amount, int[] coins) {
        return helper(coins, amount, 0);
    }

    public int helper(int[] coins, int amount, int index) {
        if (amount == 0) return 1;
        if (amount < 0 || index >= coins.length) return 0;

        int take = helper(coins, amount - coins[index], index);
        int skip = helper(coins, amount, index + 1);

        return take + skip;
    }
}