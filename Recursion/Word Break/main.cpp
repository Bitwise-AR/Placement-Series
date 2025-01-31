class Solution {
public:
    int n;
    unordered_set<string> st;
    int t[301];

    bool solve(int idx, string &s){
        if(idx >= s.size())
            return true;

        if(t[idx] != -1)
            return t[idx];
        
        if(st.find(s) != st.end())
            return true;
        
        for(int l=1; l<=n; l++) {
            string temp = s.substr(idx, l);
            if(st.find(temp) != st.end() && solve(idx+l, s))
                return t[idx] = true;
        }

        return t[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(t, -1, sizeof(t)); //initializing array 't' with '-1'

        //storing all dictionary words in set
        for(string &word : wordDict){
            st.insert(word);
        }

        return solve(0, s);
    }
};