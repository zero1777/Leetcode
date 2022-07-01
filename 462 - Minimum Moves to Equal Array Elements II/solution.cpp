class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        int sum = 0;
        sort(nums.begin(), nums.end());
        
        while (l < r) {
            sum += (nums[r--] - nums[l++]);
        } 
       
        return sum;
    }
};