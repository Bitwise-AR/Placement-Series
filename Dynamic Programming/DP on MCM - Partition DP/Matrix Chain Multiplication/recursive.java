
class Solution {
    static int matrixMultiplication(int arr[]) {
        return helper(1, arr.length-1, arr);
    }
    
    private static int helper(int i, int j, int[] arr){
        if (i >= j) return 0;
        
        int res = Integer.MAX_VALUE;
        
        for (int k=i; k<j; k++){
            int left = helper(i, k, arr);
            int right = helper(k+1, j, arr);
            int temp = arr[i-1] * arr[k] * arr[j] + left + right;
            
            res = Math.min(res, temp);
        }
        
        return res;
    }
}