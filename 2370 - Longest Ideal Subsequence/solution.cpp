class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        int maxLen = 0;
        int letters = 26;
        vector<int> dp(letters, 0);

        for (int i = 0; i < n; i++) {
            int num = s[i] - 'a';
            int left = max(0, num - k);
            int right = min(25, num + k);
            dp[num]++;
            for (int j = left; j <= right; j++) {
                if (num == j) continue;
                dp[num] = max(dp[num], 1 + dp[j]);
            }

            maxLen = max(maxLen, dp[num]);
        }

        return maxLen;
    }
};