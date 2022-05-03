class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        int l = n, r = 0;
        
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                l = min(l, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        
        while (!stk.empty()) stk.pop();
        for (int i = n-1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] < nums[i]) {
                r = max(r, stk.top());
                stk.pop();
            }
            stk.push(i);
        }
        
        return max(r - l + 1, 0);
    }
};