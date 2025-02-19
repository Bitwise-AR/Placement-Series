class recursive {
    private int helper(int i, int j, String word1, String word2) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (word1.charAt(i) == word2.charAt(j)) {
            return helper(i - 1, j - 1, word1, word2);
        }
        int insert = 1 + helper(i, j - 1, word1, word2);
        int delete = 1 + helper(i - 1, j, word1, word2);
        int replace = 1 + helper(i - 1, j - 1, word1, word2);
        return Math.min(insert, Math.min(delete, replace));
    }

    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        return helper(m - 1, n - 1, word1, word2);
    }
}
