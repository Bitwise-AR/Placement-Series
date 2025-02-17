import java.util.*;
class memoization {
    
    public int longestCommonSubstr(String s1, String s2){   
        int[][] dp = new int[s1.length() + 1][s2.length() + 1];
        for (int[] l : dp) Arrays.fill(l, -1);
        
        return helper(s1, s2, 0, 0, 0, dp);
    }
    
    private int helper(String s1, String s2, int i, int j, int res, int[][] dp)
    {
        if(i == s1.length() || j == s2.length()) return res;
        
        if (dp[i][j] != -1) return dp[i][j];
        
        if(s1.charAt(i) == s2.charAt(j)){
            res = helper(s1, s2, i + 1, j + 1, res + 1, dp);
        }
        
        int l = helper(s1, s2, i + 1, j, 0, dp);
        int r = helper(s1, s2, i, j + 1, 0, dp);
        
        return Math.max(res,Math.max(l,r));
    }
}

