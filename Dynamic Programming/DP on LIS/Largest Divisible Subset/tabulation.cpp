class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            int n = nums.size();
            sort(nums.begin(), nums.end());
            
            vector<int> dp(n, 1);
            vector<int> parent(n, -1);
    
            int maxLIS = 1;
            int lastIndex = 0;
    
            for(int i=1; i<n; i++){
                for(int j=0; j<i; j++){
                    if(nums[i] % nums[j] == 0 && dp[i] < dp[j]+1){
                        dp[i] = dp[j]+1;
                        parent[i] = j;
                    }
                }
                if(dp[i] > maxLIS){
                    maxLIS = dp[i];
                    lastIndex = i;
                }
            }
    
            vector<int> ans;
            while(lastIndex != -1){
                ans.push_back(nums[lastIndex]);
                lastIndex = parent[lastIndex];
            }
    
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };