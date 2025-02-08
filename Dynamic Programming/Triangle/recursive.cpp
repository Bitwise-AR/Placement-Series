class Solution {
    public:
        int n;
        int solve(int i, int j, vector<vector<int>> &triangle) {
            if(i == n-1){
                return triangle[i][j];
            }
            int sum = triangle[i][j];
            int down = sum + solve(i+1, j, triangle);
            int diag = sum + solve(i+1, j+1, triangle);
    
            return min(down, diag);
        }
        int minimumTotal(vector<vector<int>>& triangle) {
            n = triangle.size();
            return solve(0, 0, triangle);
        }
    };