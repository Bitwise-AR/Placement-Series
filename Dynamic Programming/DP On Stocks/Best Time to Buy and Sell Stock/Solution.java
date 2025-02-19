class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int min = prices[0];
        int profit = Integer.MIN_VALUE;
        for(int i=1;i<n;i++){
            profit = Math.max(prices[i] - min,profit);
            min = Math.min(prices[i],min);
        }
        return profit>0?profit:0;
    }
}
