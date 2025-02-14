class Solution {
    public:
      int solve(int i, int capacity, vector<int> &val, vector<int> &wt){
          if(capacity==0) return 0;
          if(i>=wt.size()) return 0;
          int take=0;
          if(capacity >= wt[i])
              take = val[i] + solve(i+1, capacity-wt[i], val, wt);
          int skip = solve(i+1, capacity, val, wt);
          return max(take, skip);
      }
      
      int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
          return solve(0, capacity, val, wt);
      }
  };