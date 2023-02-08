class Solution {
public:
    bool rowSafe(vector<vector<char>>& board, int row) {
        vector<bool> nums(9, false);
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == '.') continue;
            if (nums[board[row][col] - '0']) return false;
            nums[board[row][col] - '0'] = true;
        }
        
        return true;
    }
    bool colSafe(vector<vector<char>>& board, int col) {
        vector<bool> nums(9, false);
        for (int row = 0; row < 9; row++) {
            if (board[row][col] == '.') continue;
            if (nums[board[row][col] - '0']) return false;
            nums[board[row][col] - '0'] = true;
        }

        return true;
    }
    bool gridSafe(vector<vector<char>>& board, int grid) {
        int rowStart = grid / 3 * 3;
        int colStart = grid % 3 * 3;
        vector<bool> nums(9, false);

        for (int row = rowStart; row < rowStart + 3; row++) {
            for (int col = colStart; col < colStart + 3; col++) {
                if (board[row][col] == '.') continue;
                if (nums[board[row][col] - '0']) return false;
                nums[board[row][col] - '0'] = true;
            }
        }

        return true;
    }
    bool valid(vector<vector<char>>& board, int r, int c) {
        int grid = r / 3 * 3 + c % 3;
        return rowSafe(board, r) && colSafe(board, c) && gridSafe(board, grid);
    }
    bool solve(vector<vector<char>>& board, int r, int c) {
        // find next empty cell
        while (r < 9 && board[r][c] != '.') {
            if (c == 8) {
                r++; 
                c = 0;
            } else {
                c++;
            }
        }

        // finished
        if (r == 9) return true;

        // recursive solve 
        for (int num = 1; num <= 9; num++) {
            board[r][c] = num + '0';
            if (valid(board, r, c)) {
                if (solve(board, r, c)) return true;
            }
            board[r][c] = '.';
        }

        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};