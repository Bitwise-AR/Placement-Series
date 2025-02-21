class Solution {
    public:
        int solve(int idx, vector<int> nums, int prev){
            if(idx >= nums.size()){
                return 0;
            }
    
            int dontTake = solve(idx + 1, nums, prev);  
            int take = 0;
    
            if(prev == -1 || nums[idx] > nums[prev]) 
                take = 1 + solve(idx + 1, nums, nums[idx]);  
            
            return max(take, dontTake); 
        }
    
        int lengthOfLIS(vector<int>& nums) {
            return solve(0, nums, -1);
        }
    };