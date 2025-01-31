class Solution {
    public boolean rules(char[][] board, int row, int col, char digit) {
        // Same row or column
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == digit || board[i][col] == digit) {
                return false;
            }
        }

        // 3x3 square grid
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == digit) {
                    return false;
                }
            }
        }

        return true;
    }

    public boolean helper(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char digit = '1'; digit <= '9'; digit++) {
                        // place
                        if (rules(board, i, j, digit)) {
                            board[i][j] = digit; 

                            if (helper(board)) {
                                return true;
                            }

                            // Backtrack
                            board[i][j] = '.';
                        }
                    }

                    // no place
                    return false;
                }
            }
        }

        // Return true if the entire board is correctly filled
        return true;
    }

    public void solveSudoku(char[][] board) {
        helper(board);
    }
}