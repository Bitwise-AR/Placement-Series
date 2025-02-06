import java.util.Arrays;

class Solution {
    public int uniquePaths(int m, int n) {
        int[] above = new int[n];
        Arrays.fill(above, 1);

        for (int row = 1; row < m; row++) {
            int[] current = new int[n];
            Arrays.fill(current, 1);
            for (int col = 1; col < n; col++) {
                current[col] = current[col - 1] + above[col];
            }
            above = current;
        }

        return above[n - 1];
    }
}