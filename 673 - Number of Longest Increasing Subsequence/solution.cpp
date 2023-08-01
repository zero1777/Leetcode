class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int maxlen = 0;
        vector<int> dp(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[i] < 1 + dp[j]) {
                        dp[i] = 1 + dp[j];
                        count[i] = count[j];
                    } else if (dp[i] == 1 + dp[j]) {
                        count[i] += count[j];
                    } 
                }
            }
            maxlen = max(maxlen, dp[i]);
        }

        int maxNums = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxlen) maxNums += count[i];
        }

        return maxNums;
    }
};