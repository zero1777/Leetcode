class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int num, cnt = 0;
        int curSum = 0;
        unordered_map<int, int> prefix;

        for (int num : nums) {
            curSum += num;

            if (curSum == k) cnt++;
            if (prefix.find(curSum - k) != prefix.end()) cnt += prefix[curSum - k];
            
            prefix[curSum]++;
        }

        return cnt;
    }
};