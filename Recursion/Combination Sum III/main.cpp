class Solution {
public:
    void solve(int idx, int k, int n, vector<int>& temp, vector<int>& nums, vector<vector<int>>& ans){
        if(temp.size() == k && n == 0) {
            ans.push_back(temp);
            return;
        }

        if(idx>=nums.size() || n<0)
            return;
        
        //take
        temp.push_back(nums[idx]);
        solve(idx+1, k, n-nums[idx], temp, nums, ans);
        temp.pop_back();

        //not take
        solve(idx+1, k, n, temp, nums, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        solve(0, k, n, temp, nums, ans);
        return ans;
    }
};