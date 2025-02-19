import java.util.*;

class memoUsingMap {
    public String shortestCommonSupersequence(String str1, String str2) {
        Map<String, String> memo = new HashMap<>();
        return helper(str1, str2, 0, 0, memo);
    }

    private String helper(String str1, String str2, int i, int j, Map<String, String> memo) {
        if (i == str1.length()) return str2.substring(j);
        if (j == str2.length()) return str1.substring(i);

        String key = i + "_" + j;
        if (memo.containsKey(key)) return memo.get(key);

        String result;
        if (str1.charAt(i) == str2.charAt(j)) {
            result = str1.charAt(i) + helper(str1, str2, i + 1, j + 1, memo);
        } else {
            String temp1 = str1.charAt(i) + helper(str1, str2, i + 1, j, memo);
            String temp2 = str2.charAt(j) + helper(str1, str2, i, j + 1, memo);

            result = (temp1.length() < temp2.length()) ? temp1 : temp2;
        }

        memo.put(key, result);
        return result;
    }
}
