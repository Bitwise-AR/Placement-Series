class memoization {
    public boolean helper(int i, int j, String text, String pattern) {
        if (i < 0 && j < 0) return true;
        if (j < 0 && i >= 0) return false;
        if (i < 0 && j >= 0) {
            for (int a = 0; a <= j; a++) {
                if (pattern.charAt(a) != '*') return false;
            }
            return true;
        }

        if (text.charAt(i) == pattern.charAt(j) || pattern.charAt(j) == '?') {
            return helper(i - 1, j - 1, text, pattern);
        }

        if (pattern.charAt(j) == '*') {
            return helper(i - 1, j, text, pattern) || helper(i, j - 1, text, pattern);
        }

        return false;
    }

    public boolean isMatch(String s, String p) {
        int n1 = s.length();
        int n2 = p.length();
        return helper(n1 - 1, n2 - 1, s, p);
    }
}