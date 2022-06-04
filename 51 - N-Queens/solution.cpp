class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<int> dp(n); 
        place(dp, n, 0);
        
        return ans;
    }
    void place(vector<int> &dp, int n, int row) {
        if (row == n) {
            makeAns(dp, n);
            return ;
        } 
        
        for (int i=0; i<n; i++) {
            if (valid(dp, n, row, i)) {
                dp[row] = i;
                place(dp, n, row+1);
            }
        }
    }
    void makeAns(vector<int> &dp, int n) {
        vector<string> vec;
        for (int i=0; i<n; i++) {
            string s;
            for (int j=0; j<n; j++) {
                if (dp[i] == j) s += "Q";
                else s += ".";
            }
            vec.push_back(s);
        }
        ans.push_back(vec);
    }
    bool valid(vector<int> &dp, int n, int row, int j) {
        for (int i=0; i<row; i++) {
            if (dp[i] == j || dp[i]-j == row-i || j-dp[i] == row-i) return false;
        }
        return true;
    }
};