class memoization {
    
    public static int helper(int[] nums, int i, int target, int[][] dp) {
        if (i < 0) {
            return target == 0 ? 1 : 0;
        }
        if (dp[i][target] != -1) {
            return dp[i][target];
        }
        
        int take = 0;
        if (nums[i] <= target) {
            take = helper(nums, i - 1, target - nums[i], dp);
        }
        
        int notTake = helper(nums, i - 1, target, dp);
        
        return dp[i][target] = take + notTake;
    }
    
    public static int perfectSum(int[] nums, int target) {
        if (nums.length == 1 && nums[0] == target) return 1;
        else if (nums.length == 1 && nums[0] != target) return 0;
        
        int[][] dp = new int[nums.length][target + 1];
        
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        
        return helper(nums, nums.length - 1, target, dp);
    }
}
