class Solution {
    public int minCut(String s) {
        return helper(0, s) - 1; 
    }

    private int helper(int start, String s) {
        if (start == s.length()) return 0;

        int min = Integer.MAX_VALUE;
        for (int end = start; end < s.length(); end++) {
            if (isPalindrome(s, start, end)) {
                min = Math.min(min, 1 + helper(end + 1, s));
            }
        }
        return min;
    }

    private boolean isPalindrome(String s, int l, int r) {
        while (l < r) {
            if (s.charAt(l++) != s.charAt(r--)) return false;
        }
        return true;
    }
}