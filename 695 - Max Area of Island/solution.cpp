class Solution {
public:
    int dfs(vector<vector<int>>& grid, int n, int m, int x, int y) {
        if (x < 0 || x >= n || y < 0 || y >= m) return 0; 
        if (grid[x][y] == 0) return 0;
        grid[x][y] = 0;
        
        int left = dfs(grid, n, m, x - 1, y);
        int right = dfs(grid, n, m, x + 1, y);
        int up = dfs(grid, n, m, x, y - 1);
        int down = dfs(grid, n, m, x, y + 1);
            
        return left + right + up + down + 1;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (grid[i][j] == 1)  maxArea = max(maxArea, dfs(grid, n, m, i, j));   
            }
        }
        
        return maxArea;
    }
};