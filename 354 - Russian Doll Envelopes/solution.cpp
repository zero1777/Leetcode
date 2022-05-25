class Solution {
public:
    void binary_search(vector<int>& dp, int val) {
        int l = 0, r = dp.size() - 1;
        
        while (l <= r) {
            int m = (l + r) / 2;
            if (dp[m] < val) l = m + 1;
            else if (dp[m] > val) r = m - 1;
            else return ;
        }
        
        if (l >= dp.size()) dp.push_back(val);
        else dp[l] = val;
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        auto cmp = [] (const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);    
        };
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        
        vector<int> dp;
        for (auto envelope : envelopes) {
            binary_search(dp, envelope[1]);
        }
        
        return dp.size();
    }
};