class Solution {
public:
    string supersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        // lcs
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // backtrace
        string lcs;
        for (int i = n, j = m; i >= 1 && j >= 1; ) {
            if (str1[i-1] == str2[j-1]) {
                lcs.push_back(str1[i-1]);
                i--; 
                j--;
            } else {
                if (dp[i-1][j] > dp[i][j-1]) i--;
                else j--;
            }
        }
        std::reverse(lcs.begin(), lcs.end());

        // supersequence
        string ss;
        for (int i = 0, j = 0, k = 0; ; i++, j++) {
            if (k >= lcs.size()) {
                while (i < n) ss.push_back(str1[i++]);
                while (j < m) ss.push_back(str2[j++]);
                break;
            }

            while (i < n && str1[i] != lcs[k]) {
                ss.push_back(str1[i++]);
            }
            while (j < m && str2[j] != lcs[k]) {
                ss.push_back(str2[j++]);
            }
            ss.push_back(lcs[k++]);
        } 

        return ss;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        return supersequence(str1, str2);
    }
};