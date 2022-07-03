class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // special case, just return
        if (nums.size() < 2) return nums.size();
        
        // parameter
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);
        
        for (int i=1; i<nums.size(); i++) {
            up[i] = up[i-1];
            down[i] = down[i-1];
            if (nums[i] < nums[i-1]) {
                up[i] = down[i-1] + 1;
            } 
            else if (nums[i] > nums[i-1]) {
                down[i] = up[i-1] + 1;
            }
        }
        
        return max(up[nums.size()-1], down[nums.size()-1]);
    }
};