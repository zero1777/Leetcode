class Solution {
public:
    int sz = 51;
    int mod = 1e9 + 7;
    int dfs(vector<vector<vector<int>>>& dp, int m, int n, int move, int row, int col) {
        if (row < 0 || row >= m || col < 0 || col >= n) return 1;
        if (move == 0) return 0;
        if (dp[row][col][move] != -1) return dp[row][col][move];
        
        // up
        dp[row][col][move] = dfs(dp, m, n, move - 1, row - 1, col);
        
        // down
        dp[row][col][move] += dfs(dp, m, n, move - 1, row + 1, col);
        dp[row][col][move] %= mod;
        
        // left
        dp[row][col][move] += dfs(dp, m, n, move - 1, row, col - 1);
        dp[row][col][move] %= mod;
        
        // right
        dp[row][col][move] += dfs(dp, m, n, move - 1, row, col + 1);
        dp[row][col][move] %= mod;
        
        return dp[row][col][move];
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(sz, vector<int>(sz, -1)));
        return dfs(dp, m, n, maxMove, startRow, startColumn); 
    }
};