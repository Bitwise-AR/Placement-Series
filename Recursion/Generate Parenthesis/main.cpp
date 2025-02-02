class Solution {
public:
    void solve(int open, int close, int n, string temp, vector<string>& ans){
        if(open == 0 && close == 0) {
            ans.push_back(temp);
            return;
        }

        if(open<=close && open>0){
            temp.push_back('(');
            solve(open-1, close, n, temp, ans);
            temp.pop_back();
        }
        if(close>open && close>0) {
            temp.push_back(')');
            solve(open, close-1, n, temp, ans);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, n, n, "", ans);
        return ans;
    }
};