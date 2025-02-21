class Solution {
    public:
        bool check(string &s1, string &s2){
            if(s1.size() != s2.size()+1) return false;
    
            int first = 0;
            int second = 0;
    
            while(first < s1.size()){
                if(s1[first] == s2[second]){
                    first++;
                    second++;
                }
                else{
                    first++;
                }
            }
            if(first == second+1) return true;
            return false;
        }
    
        static bool compareByLength(string &a, string &b){
            return a.size() < b.size();
        }
    
        int longestStrChain(vector<string>& words) {
            int n = words.size();
            sort(words.begin(), words.end(), compareByLength);
            vector<int> dp(n, 1);
            int maxLIS = 1;
            
            for(int i=1; i<n; i++){
                for(int j=0; j<i; j++){
                    if(check(words[i], words[j]) && dp[j]+1 > dp[i]){
                        dp[i] = dp[j]+1;
                    }
                }
                maxLIS = max(maxLIS, dp[i]);
            }
    
            return maxLIS;
        }
    };