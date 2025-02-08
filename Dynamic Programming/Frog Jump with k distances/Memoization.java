// User function Template for Java

class Solution {
    public int minimizeCost(int k, int arr[]) {
        // code here
        int n = arr.length;
        int[] dp = new int[n];
        for(int i=0;i<n;i++){
            dp[i] = -1;
        }
        return recur(k,arr,n-1,dp);
    }
    
    public int recur(int k,int arr[], int i, int[] dp){
        if(i==0){
            dp[0] = 0;
            return 0;
        }
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        dp[i] = Integer.MAX_VALUE;
        
        for(int j=1;j<=k;j++){
            if(i-j >=0){
                int cost = Math.abs(arr[i]-arr[i-j]) + recur(k, arr, i-j, dp);
                dp[i] = Math.min(cost, dp[i]);
            }
        }
        
        return dp[i];
    }
}
