class recursive {
    public int helper(String s, String t, int i, int j) {
        if (j == t.length()) {
            return 1;
        }
        if (i == s.length()) {
            return 0;
        }

        int take = 0, notTake = 0;

        if (s.charAt(i) == t.charAt(j)) {
            take = helper(s, t, i + 1, j + 1);
        }

        notTake = helper(s, t, i + 1, j);

        return take + notTake;
    }

    public int numDistinct(String s, String t) {
        return helper(s, t, 0, 0);
    }
}