import java.util.*;

class Solution {
    static int matrixMultiplication(int arr[]) {
        int n = arr.length - 1;
        
        int[][] dp = new int[n+1][n+1];
        for (int[] l : dp) Arrays.fill(l, -1);
        
        return helper(1, n, arr, dp);
    }
    
    private static int helper(int i, int j, int[] arr, int[][] dp){
        if (i >= j) return 0;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        int res = Integer.MAX_VALUE;
        
        for (int k=i; k<j; k++){
            int left = helper(i, k, arr, dp);
            int right = helper(k+1, j, arr, dp);
            int temp = arr[i-1] * arr[k] * arr[j] + left + right;
            
            res = Math.min(res, temp);
        }
        
        return dp[i][j] = res;
    }
}