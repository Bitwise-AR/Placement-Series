class recursive {
    public String shortestCommonSupersequence(String str1, String str2) {
        return helper(str1, str2, 0, 0);
    }

    private String helper(String str1, String str2, int i, int j) {
        if (i >= str1.length() && j >= str2.length()) {
            return "";
        }
        if (i >= str1.length()) {
            return str2.substring(j);
        }
        if (j >= str2.length()) {
            return str1.substring(i);
        }

        String res;

        if (str1.charAt(i) == str2.charAt(j)) {
            res = str2.charAt(j) + helper(str1, str2, i + 1, j + 1);
        } else {
            String temp1 = str1.charAt(i) + helper(str1, str2, i + 1, j);
            String temp2 = str2.charAt(j) + helper(str1, str2, i, j + 1);

            if (temp1.length() < temp2.length()) {
                res = temp1;
            } else {
                res = temp2;
            }
        }
        return res;
    }
}