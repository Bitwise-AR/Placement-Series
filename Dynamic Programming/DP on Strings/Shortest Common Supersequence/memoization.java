class memoization {
    public String shortestCommonSupersequence(String str1, String str2) {
        String[][] dp = new String[str1.length() + 1][str2.length() + 1];
        return helper(str1, str2, 0, 0, dp);
    }

    private String helper(String str1, String str2, int i, int j, String[][] dp) {
        if (i >= str1.length() && j >= str2.length()) {
            return "";
        }
        if (i >= str1.length()) {
            return str2.substring(j);
        }
        if (j >= str2.length()) {
            return str1.substring(i);
        }

        if (dp[i][j] != null) return dp[i][j];

        String res;

        if (str1.charAt(i) == str2.charAt(j)) {
            res = str1.charAt(i) + helper(str1, str2, i + 1, j + 1, dp);
        } else {
            String temp1 = str1.charAt(i) + helper(str1, str2, i + 1, j, dp);
            String temp2 = str2.charAt(j) + helper(str1, str2, i, j + 1, dp);

            res = (temp1.length() < temp2.length()) ? temp1 : temp2;
        }
        return dp[i][j] = res;
    }
}