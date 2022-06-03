class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> tmp(n+1, vector<int>(m+1, 0));
        
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                tmp[i][j] = tmp[i-1][j] + tmp[i][j-1] + matrix[i-1][j-1] - tmp[i-1][j-1]; 
            }
        }
        
        dp = tmp;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1]; 
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */