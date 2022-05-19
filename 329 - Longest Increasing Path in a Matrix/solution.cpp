class Solution {
public:
    #define pi pair<int, int>
    int longestPath = 1;
    int n, m;
    int dir = 4;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    
    void dfs(int x, int y, vector<vector<int>>& path, vector<vector<int>>& matrix) {
        path[x][y] = 1;
        int newPath = 0;
        
        for (int i=0; i<dir; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= n || nx < 0 || ny >= m || ny < 0) continue;
            if (matrix[nx][ny] <= matrix[x][y]) continue;
            
            if (path[nx][ny] == 0) dfs(nx, ny, path, matrix);
            
            newPath = max(newPath, path[nx][ny]);
        }
        
        path[x][y] += newPath;
        longestPath = max(longestPath, path[x][y]);
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> path(n, vector<int>(m, 0));
        
        vector<pi> candidates;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (path[i][j] == 0) {
                    dfs(i, j, path, matrix);         
                }
            }
        }
        
        return longestPath;
    }
};