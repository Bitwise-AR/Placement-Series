class Solution {
    public int maxCoins(int[] nums) {
        int[] nums2 = new int[nums.length + 2];
        nums2[0] = 1;
        nums2[nums2.length - 1] = 1;
        System.arraycopy(nums, 0, nums2, 1, nums.length);
        
        return helper(nums2, 1, nums.length);
    }

    private int helper(int[] arr, int i, int j) {
        if (i > j) return 0;

        int res = 0;
        for (int k = i; k <= j; k++) { 
            int coins = arr[i - 1] * arr[k] * arr[j + 1] 
                        + helper(arr, i, k - 1) 
                        + helper(arr, k + 1, j);
            res = Math.max(res, coins);
        }
        
        return res;
    }
}