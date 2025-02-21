class Solution {
    public:
        void solve(int i, int prevIdx, vector<int>& temp, vector<int>& result, vector<int>& nums){
            if(i >= nums.size()){
                if(temp.size() > result.size())
                    result = temp;
                return;
            }
    
            if(prevIdx == -1 || nums[i] % nums[prevIdx] == 0){
                temp.push_back(nums[i]);
                solve(i+1, i, temp, result, nums);
                temp.pop_back();
            }
    
            solve(i+1, prevIdx, temp, result, nums);
        }
    
        vector<int> largestDivisibleSubset(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<int> result;
            vector<int> temp;
            int prevIdx = -1;
            solve(0, prevIdx, temp, result, nums);
            return result;
        }
    };