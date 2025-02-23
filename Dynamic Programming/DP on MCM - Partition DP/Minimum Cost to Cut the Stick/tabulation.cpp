class Solution {
    public:
        int minCost(int n, vector<int>& cuts) {
            sort(cuts.begin(), cuts.end());
            
            cuts.insert(cuts.begin(), 0);
            cuts.push_back(n);
    
            int dp[103][103];
            int m = cuts.size();
    
            for (int i = m-1; i >= 0; i--) {
                for (int j = i+1; j <= m-1; j++) {
                    if (j-i < 2) continue;
                    int mini = 1e7;
                    for (int idx = i+1; idx < j; idx++) {
                        int cost = (cuts[j] - cuts[i]) + dp[i][idx] + dp[idx][j];
                        mini = min(mini, cost);
                    }
                    dp[i][j] = mini;
                }
            }
    
            return dp[0][m - 1];
        }
    };