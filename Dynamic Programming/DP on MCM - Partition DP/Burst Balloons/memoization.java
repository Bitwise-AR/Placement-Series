import java.util.*;

class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int[] nums2 = new int[n + 2];
        nums2[0] = 1;
        nums2[nums2.length - 1] = 1;
        
        System.arraycopy(nums, 0, nums2, 1, n);

        int[][] dp = new int[n+2][n+2];
        for(int[] l: dp) Arrays.fill(l, -1);
        
        return helper(nums2, 1, nums.length, dp);
    }

    private int helper(int[] arr, int i, int j, int[][] dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int res = 0;
        for (int k = i; k <= j; k++) { 
            int coins = arr[i - 1] * arr[k] * arr[j + 1] 
                        + helper(arr, i, k - 1, dp) 
                        + helper(arr, k + 1, j, dp);
            res = Math.max(res, coins);
        }
        
        return dp[i][j] = res;
    }
}
