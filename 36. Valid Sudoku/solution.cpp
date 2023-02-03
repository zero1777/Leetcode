class Solution {
public:
    const int puzzle_size = 9;
    bool rowSafe(vector<vector<char>>& board, int row) {
        vector<bool> nums(puzzle_size, false);
        for (int col = 0; col < puzzle_size; col++) {
            if (board[row][col] == '.') continue;
            if (nums[board[row][col] - '0']) return false;
            nums[board[row][col] - '0'] = true;
        }
        
        return true;
    }
    bool colSafe(vector<vector<char>>& board, int col) {
        vector<bool> nums(puzzle_size, false);
        for (int row = 0; row < puzzle_size; row++) {
            if (board[row][col] == '.') continue;
            if (nums[board[row][col] - '0']) return false;
            nums[board[row][col] - '0'] = true;
        }
        
        return true;
    }
    bool gridSafe(vector<vector<char>>& board, int grid) {
        int colStart = (grid % 3) * 3;
        int rowStart = (grid / 3) * 3;
        vector<bool> nums(puzzle_size, false);
        for (int row = rowStart; row < rowStart + 3; row++) {
            for (int col = colStart; col < colStart + 3; col++) {
                if (board[row][col] == '.') continue;
                if (nums[board[row][col] - '0']) return false;
                nums[board[row][col] - '0'] = true;
            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < puzzle_size; i++) {
            if (!rowSafe(board, i) || !colSafe(board, i) || !gridSafe(board, i)) return false;
        }

        return true;
    }
}