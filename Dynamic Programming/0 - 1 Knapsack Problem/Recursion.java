class Solution {
    // Function to return max value that can be put in knapsack of capacity.
    static int knapSack(int capacity, int val[], int wt[]) {
        // code here
        int n = val.length;
        return recur(capacity, val, wt, 0,n);
    }
    
    public static int recur(int capacity, int[] val, int[] wt, int ind, int n){
        if(capacity == 0 || ind == n){
            return 0;
        }
        
        int take = Integer.MIN_VALUE;
        if(wt[ind] <= capacity){
            take = val[ind] + recur(capacity - wt[ind], val, wt, ind + 1,n);
        }
        
        int notTake = 0 + recur(capacity, val, wt, ind + 1,n);
        
        return Math.max(take, notTake);
    }
}