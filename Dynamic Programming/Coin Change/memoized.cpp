class Solution {
    public:
        int dp[10001];
        int solve(int amt, vector<int>& coins){
            if(amt == 0)
                return 0;
            
            if(dp[amt] != -1)
                return dp[amt];
    
            int ans = INT_MAX;
            for(int coin : coins){
                if(amt-coin >= 0) //ensuring amt stays positive
                    ans = min(ans + 0LL, 1LL + solve(amt-coin, coins));
            }
            return dp[amt] = ans;
        }
    
        int coinChange(vector<int>& coins, int amount) {
            memset(dp, -1, sizeof(dp));
            int ans = solve(amount, coins);
            return ans==INT_MAX ? -1 : ans;
        }
    };