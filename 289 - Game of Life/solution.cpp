class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // nextState curState
        // 0: dead, 1: live
        // 00, 01, 10, 11
        
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int liveCnt = 0;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        int newi = i + di;
                        int newj = j + dj;
                        if (newi >= 0 && newi < m && newj >= 0 && newj < n) {
                            if (board[newi][newj] & 1) liveCnt++;
                        }
                    }
                }
                
                if (board[i][j] & 1) {
                    if (liveCnt == 3 || liveCnt == 4) board[i][j] = board[i][j] | 2;   
                } else {
                    if (liveCnt == 3) board[i][j] = board[i][j] | 2;
                }
            }
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = board[i][j] >> 1;
            }
        }
    }
};