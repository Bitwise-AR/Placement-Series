class Solution {
public:
    int n;
    int t[201][201];

    int solve(int i, int j, vector<vector<int>> &triangle) {
        if(i == n-1){
            return triangle[i][j];
        }

        if(t[i][j] != -1)
            return t[i][j];
        
        int sum = triangle[i][j];
        int down = sum + solve(i+1, j, triangle);
        int diag = sum + solve(i+1, j+1, triangle);

        return t[i][j] = min(down, diag);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, triangle);
    }
};