class Solution {
    public:
        vector<vector<int>> dp;
        bool solve(int i, int sum, int target, vector<int> &nums){
            if (sum == target) 
                return true;
            
            if (i >= nums.size() || sum > target) 
                return false;
    
            if (dp[i][sum] != -1) 
                return dp[i][sum];
    
            bool take = solve(i + 1, sum + nums[i], target, nums);
            bool notTake = solve(i + 1, sum, target, nums);
    
            return dp[i][sum] = take || notTake;
        }
    
        bool canPartition(vector<int>& nums) {
            int totalSum = accumulate(nums.begin(), nums.end(), 0);
    
            if (totalSum % 2) 
                return false;
    
            int target = totalSum / 2;
            dp.resize(nums.size(), vector<int>(target + 1, -1));
    
            return solve(0, 0, target, nums);
        }
    };