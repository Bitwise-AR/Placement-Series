class Solution {
    public int longestCommonSubstr(String s1, String s2){   
        return helper(s1, s2, 0, 0, 0);
    }
    
    private int helper(String s1, String s2, int i, int j, int res)
    {
        if(i == s1.length() || j == s2.length()) return res;
        
        if(s1.charAt(i) == s2.charAt(j)){
            res = helper(s1, s2, i + 1, j + 1, res + 1);
        }
        
        int l = helper(s1, s2, i + 1, j, 0);
        int r = helper(s1, s2, i, j + 1, 0);
        
        return Math.max(res, Math.max(l, r));
    }
}

