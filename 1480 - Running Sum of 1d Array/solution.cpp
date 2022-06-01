class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int prefix = 0;
        
        for (auto num : nums) {
            prefix += num;
            ans.push_back(prefix);
        }
        
        return ans;
    }
};