class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxSum = 0, sum = 0;
        unordered_set<int> st; 
           
        while (right < n) {
            sum += nums[right];
            
            while (st.find(nums[right]) != st.end()) {
                sum -= nums[left];
                st.erase(nums[left++]);
            }
            st.insert(nums[right++]);
            
            maxSum = max(maxSum, sum);
        }
        
        return maxSum;
    }
};