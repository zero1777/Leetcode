class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if (n + m != s3.length()) return false;
        
        vector<bool> dp(m+1, false);
        
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=m; j++) {
                if (i == 0 && j == 0) {
                    dp[j] = true;
                    continue;
                }
                
                int t = i + j - 1;
                if (i == 0) {
                    if (s3[t] == s2[j-1]) dp[j] = dp[j] || dp[j-1];
                } 
                else if (j == 0) {
                    if (s3[t] != s1[i-1]) dp[j] = false;
                } 
                else {
                    if (s3[t] != s1[i-1]) dp[j] = false;
                    if (s3[t] == s2[j-1]) dp[j] = dp[j] || dp[j-1];
                }
            }
        }
        
        return dp[m];
    }
};