class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int odd = 0;
        
        for (int cur = 0; cur < n; cur++) {
            while (odd < cur && nums[odd] % 2 == 0) odd++;
            if (nums[cur] % 2 == 0 && nums[odd] % 2 == 1) swap(nums[cur], nums[odd]);
        }
        
        return nums;
    }
};