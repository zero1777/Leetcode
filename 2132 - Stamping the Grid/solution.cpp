class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n+1, vector<int>(m+1, 0));
        vector<vector<int>> stamped(n+1, vector<int>(m+1, 0));
        
        // produce the 2D prefix sum
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + grid[i-1][j-1]; 
        
        // early stop
        if (prefix[n][m] == n * m) return true;
        if (stampHeight > n || stampWidth > m) return false;
        
        // calculated the covered grid
        for (int i=stampHeight; i<=n; i++) {
            for (int j=stampWidth; j<=m; j++) {
                if (grid[i-1][j-1]) continue;
                if (prefix[i][j] - prefix[i][j-stampWidth] - prefix[i-stampHeight][j] + prefix[i-stampHeight][j-stampWidth] == 0) stamped[i][j]++;
            }
        }
        
        // produce the 2D prefix sum
        for (int i=1; i<=n; i++)
            for (int j=1; j<=m; j++)
                stamped[i][j] += stamped[i-1][j] + stamped[i][j-1] - stamped[i-1][j-1];
        
        // check all the empty grids are stamped
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                if (grid[i-1][j-1]) continue;
                int ni = min(n, i + stampHeight - 1);
                int nj = min(m, j + stampWidth - 1);
                if (stamped[ni][nj] - stamped[ni][j-1] - stamped[i-1][nj] + stamped[i-1][j-1] == 0) return false;
            }
        }
        return true;
    }
};