import java.util.Arrays;

public class memoization {
    
    static Boolean helper(int arr[], int[][] dp, int target,int i) {
        if(target == 0) return true; 
        
        if(i == 0){ 
            return arr[i] == target;
        }
        
        if (dp[i][target] != -1) {
            return dp[i][target] == 1; 
        }
        
        Boolean take=false, nottake = false;
         
        if(arr[i] <= target) {
            take = helper(arr, dp, target-arr[i], i-1);
        }
        nottake = helper(arr, dp, target, i-1);
        
        if (take || nottake) {
            dp[i][target] = 1;
        } else{
            dp[i][target] = 0; 
        }
        
        return dp[i][target] == 1;
    }

    static Boolean isSubsetSum(int arr[], int target) {
        int[][] dp = new int[arr.length][target+1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }
        Boolean ans = helper(arr, dp, target, arr.length-1);
        return ans;
    }
}
