import java.util.*;

class memoization {
    private int helper(int i, int j, String word1, String word2, int[][] dp) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (word1.charAt(i) == word2.charAt(j)) {
            return helper(i - 1, j - 1, word1, word2, dp);
        }

        if (dp[i][j] != -1) return dp[i][j];

        int insert = 1 + helper(i, j - 1, word1, word2, dp);
        int delete = 1 + helper(i - 1, j, word1, word2, dp);
        int replace = 1 + helper(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = Math.min(insert, Math.min(delete, replace));
    }

    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();

        int[][] dp = new int[m+1][n+1];
        for (int[] l : dp) Arrays.fill(l, -1);
        
        return helper(m - 1, n - 1, word1, word2, dp);
    }
}