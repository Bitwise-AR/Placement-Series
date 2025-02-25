class Solution {
    public:
        bool isPalindrome(int l, int r, string &s){
            while(l < r){
                if(s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        }
    
        int minCut(string s) {
            int n = s.size();
            vector<int> dp(n+1, 0);
            for(int i=n-1; i>=0; i--){
                int minCost = INT_MAX;
                for(int j=i; j<=n-1; j++){
                    if(isPalindrome(i, j, s)){
                        int cost = 1 + dp[j+1];
                        minCost = min(minCost, cost);
                    }
                }
                dp[i] = minCost;
            }
    
            return dp[0] - 1;
        }
    };
    
    /* NOTE:
        dp[0] - 1 subtracting 1 because
        e.g. abc -> a|b|c| -> will have 3 partition but actually it should be 
                    a|b|c  -> and this should be correct.
    */