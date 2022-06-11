class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0, cur = 0;
        for (auto num : nums) total += num;
       
        if (total < x) return -1;
        
        int op = -1;
        for (int left = 0, right = 0; right < n; right++) {
            cur += nums[right];
            while (cur > total - x) cur -= nums[left++];
            if (cur == total - x) op = max(op, right - left + 1);
        } 
        
        return (op == -1) ? -1 : n - op;
    }
};