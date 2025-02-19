// Would result in a TLE

class recursion {
    public int helper(int r, int c, int m, int n){
        if (r == n-1 || c == m-1) return 1;
        return helper(r+1, c, m, n) + helper(r, c+1, m, n);
    }

    public int uniquePaths(int m, int n){
        return helper(0, 0, m, n);
    }
}