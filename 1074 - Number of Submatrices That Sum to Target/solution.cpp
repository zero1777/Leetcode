class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        // 2D prefix sum
        dp[0][0] = matrix[0][0];
        for (int i=1; i<n; i++) dp[i][0] = dp[i-1][0] + matrix[i][0];
        for (int j=1; j<m; j++) dp[0][j] = dp[0][j-1] + matrix[0][j];
        
        for (int i=1; i<n; i++) {
            for (int j=1; j<m; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i][j];
            }
        }
        
        // subarray calculation
        int ret = 0;
        
        for (int i=0; i<n; i++) {
            for (int k=i; k<n; k++) {
                unordered_map<int, int> mp;
                for (int j=0; j<m; j++) {
                    int curSum;
                    if (i == 0) curSum = dp[k][j];
                    else curSum = dp[k][j] - dp[i-1][j];
                    
                    if (curSum == target) ret++;
                    if (mp.find(curSum - target) != mp.end()) ret += mp[curSum - target];
                    mp[curSum]++;
                } 
            }
        }
        
        return ret;
    }
};