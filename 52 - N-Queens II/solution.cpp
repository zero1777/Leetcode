class Solution {
public:
    int cnt = 0;
    int totalNQueens(int n) {
        vector<int> dp(n);
        place(dp, n, 0);
        
        return cnt;
    }
    void place(vector<int> &dp, int n, int row) {
        if (row == n) {
            cnt++;
            return ;
        } 
        
        for (int i=0; i<n; i++) {
            if (valid(dp, n, row, i)) {
                dp[row]  = i;
                place(dp, n, row+1);
            }
        }
    }
    bool valid(vector<int> &dp, int n, int row, int j) {
        for (int i=0; i<row; i++) {
            if (dp[i] == j || dp[i]-j == row-i || j-dp[i] == row-i) return false;
        }
        return true;
    }
};