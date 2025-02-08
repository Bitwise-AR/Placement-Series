class Solution {
    public int maximumPoints(int arr[][]) {
        // code here
        int rowSize = arr.length;
        return recur(arr, rowSize, 0, -1);
    }
    
    public int recur(int[][] arr, int rowSize, int index,int lastIndex){
        if(index == rowSize){
            return 0;
        }
        
        int maxValue = 0;
        for(int j=0;j<=2;j++){
            if(j != lastIndex){
                int val = arr[index][j] + recur(arr, rowSize, index + 1,j);
                maxValue = Math.max(val, maxValue);
            } 
        }
        
        return maxValue;
    }
}