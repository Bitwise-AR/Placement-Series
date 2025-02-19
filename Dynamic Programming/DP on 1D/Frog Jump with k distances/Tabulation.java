// User function Template for Java

class Solution {
    public int minimizeCost(int k, int arr[]) {
        int n = arr.length;
        int[] dp = new int[n];
        
        dp[0] = 0;
        
        for (int i = 1; i < n; i++) {
            int minCost = Integer.MAX_VALUE;
            
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    int cost = Math.abs(arr[i] - arr[i - j]) + dp[i - j];
                    minCost = Math.min(minCost, cost);
                }
            }
            
            dp[i] = minCost;  
        }
        
        return dp[n - 1];  
    }
}

