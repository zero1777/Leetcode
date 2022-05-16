class Solution {
public:
    #define pi pair<int, int>
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) return -1;
        
        queue<pair<pi, int>> qu;
        vector<vector<bool>> vis(n, vector<bool>(n, false)); 
        int dst = -1;
        qu.push({{0, 0}, 1});
        
        while (!qu.empty()) {
            auto [coord, len] = qu.front();
            qu.pop();
            int x = coord.first, y = coord.second;
            
            if (vis[x][y]) continue;
            vis[x][y] = true;
            
            if (x == n-1 && y == n-1) {
                dst = len;
                break;
            }
            
            for (int i=-1; i<=1; i++) {
                for (int j=-1; j<=1; j++) {
                    int ni = x + i;
                    int nj = y + j;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
                    
                    if (!vis[ni][nj] && grid[ni][nj] == 0) qu.push({{ni, nj}, len + 1}); 
                }
            }
        }
        
        return dst;
    }
};