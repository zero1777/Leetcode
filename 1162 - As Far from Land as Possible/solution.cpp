class Solution {
public:
    typedef pair<int, int> coord;
    bool inGrid(int x, int y, int n) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        queue<coord> qu;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    vis[i][j] = true;
                    qu.push({i, j});
                }
            }
        }    
        
        // no land or water exists, return -1
        if (qu.size() == n*n) return -1;

        int maxDis = -1;
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        while (!qu.empty()) {
            maxDis++;
            int sz = qu.size();
            for (int k = 0; k < sz; k++) {
                auto [x, y] = qu.front();
                qu.pop();

                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (inGrid(nx, ny, n) && !vis[nx][ny]) {
                        qu.push({nx, ny});
                        vis[nx][ny] = true;
                    }
                }
            }
        }

        return maxDis;
    }
};