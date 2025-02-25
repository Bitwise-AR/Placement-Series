class Solution {
    public:
        vector<int> dp;
        bool isPalindrome(int l, int r, string &s){
            while(l < r){
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        }
    
        int solve(int i, string& s) {
            if(i >= s.size()) return 0;
    
            if(dp[i] != -1) return dp[i];
    
            int minCost = INT_MAX;
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(i, j, s)){
                    int cost = 1 + solve(j+1, s);
                    minCost = min(minCost, cost);
                }
            }
    
            return dp[i] = minCost;
        }
    
        int minCut(string s) {
            dp.assign(s.size()+1, -1);
            return solve(0, s) - 1;
        }
    };