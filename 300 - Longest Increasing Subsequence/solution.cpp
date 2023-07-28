// Recursion + Memoization
class Solution {
public:
    int maxLength = 1;
    int lis(vector<int>& nums, int n, vector<int>& dp) {
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        
        for (int i = 0; i < n; i++) {
            dp[i] = lis(nums, i, dp);
            if (nums[i] < nums[n]) {
                dp[n] = max(dp[n], 1 + dp[i]);
            }
        }
        dp[n] = max(1, dp[n]);
        maxLength = max(maxLength, dp[n]);

        return dp[n];
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        lis(nums, n-1, dp);

        return maxLength;
    }
};

// DP
class Solution {
public:
    int lis(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 1;
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) dp[i] = max(dp[i], 1 + dp[j]);
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
    int lengthOfLIS(vector<int>& nums) {
        return lis(nums);
    }
};