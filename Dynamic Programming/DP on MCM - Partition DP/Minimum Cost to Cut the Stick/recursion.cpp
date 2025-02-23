class Solution {
    public:
        int solve(int i, int j, vector<int>& cuts){
            if(j-i < 2) return 0;
            int mini = 1e9;
            for(int idx = i+1; idx<=j-1; idx++){
                int cost = cuts[j] - cuts[i] + solve(i, idx, cuts) + solve(idx, j, cuts);
                mini = min(mini, cost);
            }
            return mini;
        }
    
        int minCost(int n, vector<int>& cuts) {
            sort(cuts.begin(), cuts.end());
            cuts.insert(cuts.begin(), 0);
            cuts.push_back(n);
    
            return solve(0, cuts.size()-1, cuts);
        }
    };