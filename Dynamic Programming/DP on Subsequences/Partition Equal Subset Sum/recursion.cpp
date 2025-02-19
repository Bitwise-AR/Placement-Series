class Solution {
    public:
    
        bool solve(int i, int sum, int target, vector<int> &nums){
            if (sum == target) 
                return true;
            
            if (i >= nums.size() || sum > target) 
                return false;
    
            bool take = solve(i + 1, sum + nums[i], target, nums);
            bool notTake = solve(i + 1, sum, target, nums);
    
            return take || notTake;
        }
    
        bool canPartition(vector<int>& nums) {
            int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
            if (totalSum % 2) 
                return false;
    
            int target = totalSum / 2;
    
            return solve(0, 0, target, nums);
        }
    };