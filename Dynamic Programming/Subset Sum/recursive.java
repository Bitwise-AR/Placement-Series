class recursive {
    
    static Boolean helper(int arr[],int target,int i) {
        if(target==0) return true; 
        
        if(i==0){ 
            return arr[i]==target;
        }
        
        Boolean take=false, nottake =false;
         
        if(arr[i]<target) take=helper(arr,target-arr[i],i-1);
        
        nottake=helper(arr,target,i-1);
          
        return (take||nottake);
    }

    static Boolean isSubsetSum(int arr[], int target) {
        Boolean ans=helper(arr,target,arr.length-1);
        return ans;
    }
}