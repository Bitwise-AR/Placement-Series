class Solution {
public:
    void solve(vector<int>& candidates, int target, int index,
               vector<int>& validCombo, vector<vector<int>>& ans) {
        if (target < 0)
            return;
        if (target == 0) {
            ans.push_back(validCombo);
            return;
        }

        for(int i=index; i<candidates.size(); i++) {
            if(i>index && candidates[i] == candidates[i-1]) continue;

            int element = candidates[i];
            validCombo.push_back(element);
            solve(candidates, target-element, i+1, validCombo, ans);
            validCombo.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> validCombo;
        int index = 0;
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, index, validCombo, ans);
        return ans;
    }
};