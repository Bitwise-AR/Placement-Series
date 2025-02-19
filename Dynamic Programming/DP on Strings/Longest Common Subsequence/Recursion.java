class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int n1 = text1.length();
        int n2 = text2.length();

        return recur(text1, text2, n1 - 1, n2 - 1);
    }

    public int recur(String text1, String text2, int n1, int n2){
        if(n1 < 0 || n2 < 0){
            return 0;
        }

        if(text1.charAt(n1) == text2.charAt(n2)){
            return 1 + recur(text1, text2, n1 - 1, n2 - 1);
        }

        return Math.max(recur(text1, text2, n1 - 1, n2) , recur(text1, text2, n1, n2 - 1));
    }
}
