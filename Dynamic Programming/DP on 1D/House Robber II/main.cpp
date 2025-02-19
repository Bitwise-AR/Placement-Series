class Solution {
public:
    int solve(int idx, vector<int>& nums, int n, vector<int> &dp) {
        if(idx > n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];

        int take = nums[idx] + solve(idx+2, nums, n, dp);
        int skip = solve(idx+1, nums, n, dp);

        return dp[idx] = max(take, skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n==1)
            return nums[0];
        
        if(n==2)
            return max(nums[0], nums[1]);

        //case-1 : take 0th index house
        vector<int> dp(n, -1);
        int take_0th_index_house = solve(0, nums, n-2, dp);

        //case-2 : take 1st index house
        dp.assign(n, -1);
        int take_1st_index_house = solve(1, nums, n-1, dp);

        return max(take_0th_index_house, take_1st_index_house);
    }
    
};