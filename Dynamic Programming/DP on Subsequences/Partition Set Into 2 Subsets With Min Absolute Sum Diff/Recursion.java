class Solution {
    int n;
    int minDiff = Integer.MAX_VALUE;

    public int minimumDifference(int[] nums) {
        n = nums.length / 2;
        helper(nums, 0, 0, 0, 0, 0);
        return minDiff;
    }

    private void helper(int[] nums, int index, int sum1, int count1, int sum2, int count2) {
        if (count1 == n && count2 == n) {
            minDiff = Math.min(minDiff, Math.abs(sum1 - sum2));
            return;
        }

        if (index == nums.length) {
            return;
        }

        if (count1 < n) {
            helper(nums, index + 1, sum1 + nums[index], count1 + 1, sum2, count2);
        }

        if (count2 < n) {
            helper(nums, index + 1, sum1, count1, sum2 + nums[index], count2 + 1);
        }
    }
}