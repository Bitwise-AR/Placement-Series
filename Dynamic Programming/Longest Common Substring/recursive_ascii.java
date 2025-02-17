class recursive_ascii {
    public int longestCommonSubstr(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        
        int[][] dp = new int[m + 1][n + 1]; 
        int maxLen = 0; 

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if ((int) s1.charAt(i - 1) == (int) s2.charAt(j - 1)) { 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxLen = Math.max(maxLen, dp[i][j]); 
                }
            }
        }
        return maxLen;
    }    
}
