import java.util.*;

class memoization {
    public List<String> all_longest_common_subsequences(String s, String t) {
        int m = s.length();
        int n = t.length();

        int[][] dp = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1))
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        Set<String> result = new HashSet<>();
        helper(dp, s, t, m, n, "", result);

        List<String> out = new ArrayList<>(result);
        Collections.sort(out);
        return out;
    }

    private void helper(int[][] dp, String s, String t, int i, int j, String current, Set<String> result) {
        if (i == 0 || j == 0) {
            result.add(new StringBuilder(current).reverse().toString());
            return;
        }

        if (s.charAt(i - 1) == t.charAt(j - 1)) {
            // Take
            helper(dp, s, t, i - 1, j - 1, current + s.charAt(i - 1), result);
        } else {
            // Not Take
            if (dp[i - 1][j] > dp[i][j - 1]) {
                helper(dp, s, t, i - 1, j, current, result);
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                helper(dp, s, t, i, j - 1, current, result);
            } else {
                helper(dp, s, t, i - 1, j, current, result);
                helper(dp, s, t, i, j - 1, current, result);
            }
        }
    }
}