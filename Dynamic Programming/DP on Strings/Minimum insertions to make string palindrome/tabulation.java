public class tabulation {
    private int helper(String s, String rev){
        int m = s.length();
        int n = rev.length();

        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s.charAt(i - 1) == rev.charAt(j - 1)){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else{
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    public int minInsertions(String s) {
        String rev = new StringBuilder(s).reverse().toString();
        int lcs = helper(s, rev);
        return s.length() - lcs;
    }
}
