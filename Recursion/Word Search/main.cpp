class Solution {
public:
    int m, n;
    bool solve(int i, int j, vector<vector<char>>& board, string& word, int idx) {
        if(idx >= word.size()) 
            return true;

        if(i<0 || j<0 || i>=m || j>=n || board[i][j] != word[idx]) 
            return false;
        
        char temp = board[i][j];
        board[i][j] = '#';

        bool down  = solve(i+1, j, board, word, idx+1);
        bool right = solve(i, j+1, board, word, idx+1);
        bool up    = solve(i-1, j, board, word, idx+1);
        bool left  = solve(i, j-1, board, word, idx+1);

        board[i][j] = temp;

        return down || right || up || left;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0])
                    if( solve(i, j, board, word, 0) )
                        return true;
            }
        }

        return false;
    }
};