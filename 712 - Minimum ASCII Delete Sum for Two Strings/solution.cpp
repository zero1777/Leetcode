class Solution {
public:
    int lcs(string &s1, string &s2) {
        int n = s1.size(); 
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = s1[i-1] + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        return dp[n][m];
    }
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        for (auto s : s1) sum += s;
        for (auto s : s2) sum += s;

        return sum - 2 * lcs(s1, s2);
    }
};