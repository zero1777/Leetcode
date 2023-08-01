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

// binary search
class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;

        while (start < end) {
            mid = start + (end - start) / 2;
            if (nums[mid] < target) start = mid + 1;
            else end = mid;
        }

        return start;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp;

        for (int i = 0; i < n; i++) {
            if (i == 0 || nums[i] > dp.back()) {
                dp.push_back(nums[i]);
            } 
            else {
                int ret = lower_bound(dp, nums[i]);
                dp[ret] = nums[i];
            }
        }

        return dp.size(); 
    }
};