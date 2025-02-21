class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
            for(int i=n-1; i>=0; i--){
                for(int prevIdx = i-1; prevIdx >= -1; prevIdx--){
                    int skip = dp[i+1][prevIdx+1];
                    int take = 0;
                    if(prevIdx == -1 || nums[i] > nums[prevIdx])
                        take = 1 + dp[i+1][i+1];
                    dp[i][prevIdx+1] = max(take, skip);
                }
            }
    
            return dp[0][0];
        }
    };