class Solution {
    public int minCut(String s) {
        int[] dp = new int[s.length()];
        return helper(0, s, dp) - 1; 
    }

    private int helper(int start, String s, int[] dp) {
        if (start == s.length()) return 0;
        if (dp[start] != 0) return dp[start];

        int min = Integer.MAX_VALUE;
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                min = Math.min(min, 1 + helper(end + 1, s, dp));
            }
        }
        return dp[start] = min;
    }

    private boolean isPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
}