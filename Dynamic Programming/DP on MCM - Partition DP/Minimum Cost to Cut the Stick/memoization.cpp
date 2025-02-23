class Solution {
    public:
        int dp[103][103];
        int solve(int i, int j, vector<int>& cuts){
            if(j-i < 2) return 0;
            
            if(dp[i][j] != -1) return dp[i][j];
            
            int mini = 1e9;
            
            for(int idx = i+1; idx<=j-1; idx++){
                int cost = cuts[j] - cuts[i] + solve(i, idx, cuts) + solve(idx, j, cuts);
                mini = min(mini, cost);
            }
            
            return dp[i][j] = mini;
        }
    
        int minCost(int n, vector<int>& cuts) {
            sort(cuts.begin(), cuts.end());
            
            cuts.insert(cuts.begin(), 0);
            cuts.push_back(n);
            
            memset(dp, -1, sizeof(dp));
            
            return solve(0, cuts.size()-1, cuts);
        }
    };