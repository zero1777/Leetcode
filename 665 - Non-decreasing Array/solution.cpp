class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int down = 0;
        int n = nums.size();
        
        for (int i=1; i<n; i++) {
            if (nums[i] < nums[i-1]) {
                down++;
                if (down > 1) return false;
                if (i >= 2 && nums[i] < nums[i-2]) nums[i] = nums[i-1];
            }
        }
        
        return true;
    }
};