class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1, 1);
        int stride = 2;
        int cnt = 0;
        dp[0] = 0;

        for (int i = 2; i <= n; i++) {
            if (cnt == stride) {
                stride <<= 1;
                cnt = 0;
            }
            dp[i] += dp[i - stride]; 
            cnt++;
        }

        return dp;
    }
};