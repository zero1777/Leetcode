class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> mins;
        int min = INT_MAX;
        for (int n : nums) {
            min = (n < min) ? n : min;
            mins.push_back(min);
        }
        
        stack <int> stk;
        for (int i=nums.size()-1; i>=0; i--) {
            if (nums[i] > mins[i]) {
                while (!stk.empty() && stk.top() <= mins[i]) stk.pop();
                if (!stk.empty() && stk.top() < nums[i]) return true;
                stk.push(nums[i]);
            }
        }
    
        return false;
    }
};