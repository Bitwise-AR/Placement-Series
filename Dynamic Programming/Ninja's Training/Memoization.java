import java.util.*;

class Solution {
    public int maximumPoints(int arr[][]) {
        int rowSize = arr.length;
        int[][] dp = new int[rowSize][4]; 
        
        for(int[] row : dp){
            Arrays.fill(row, -1);
        }
        
        return recur(arr, rowSize, 0, 3, dp);  
    }
    
    public int recur(int[][] arr, int rowSize, int index, int lastActivity, int[][] dp) {
        if(index == rowSize){
            return 0;
        }
        
        if(lastActivity != 3 && dp[index][lastActivity] != -1){
            return dp[index][lastActivity];
        }
        
        int maxValue = 0;
        for(int j = 0; j <= 2; j++){
            if(j != lastActivity){
                int val = arr[index][j] + recur(arr, rowSize, index + 1, j, dp);
                maxValue = Math.max(val, maxValue);
            } 
        }
        
        return dp[index][lastActivity] = maxValue;  
    }
}