import java.util.*;

class memoization {
    public int helper(String s, String t, int i, int j, int[][] dp) {
        if (j == t.length()) {
            return 1;
        }
        if (i == s.length()) {
            return 0;
        }

        if (dp[i][j] != -1) return dp[i][j];

        int take = 0, notTake = 0;

        if (s.charAt(i) == t.charAt(j)) {
            take = helper(s, t, i + 1, j + 1, dp);
        }

        notTake = helper(s, t, i + 1, j, dp);

        return dp[i][j] = take + notTake;
    }

    public int numDistinct(String s, String t) {
        int[][] dp = new int[s.length()+1][t.length()+1];
        for (int[] e : dp) Arrays.fill(e, -1);
        
        return helper(s, t, 0, 0, dp);
    }
}