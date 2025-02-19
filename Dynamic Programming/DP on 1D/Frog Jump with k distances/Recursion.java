// User function Template for Java

class Solution {
    public int minimizeCost(int k, int arr[]) {
        // code here
        int n = arr.length;
        return recur(k,arr,n-1);
    }
    
    public int recur(int k,int arr[], int i){
        if(i==0){
            return 0;
        }
        
        int minCost = Integer.MAX_VALUE;
        
        for(int j=1;j<=k;j++){
            if(i-j >=0){
                int cost = Math.abs(arr[i]-arr[i-j]) + recur(k,arr,i-j);
                minCost = Math.min(cost, minCost);
            }
        }
        
        return minCost;
    }
}