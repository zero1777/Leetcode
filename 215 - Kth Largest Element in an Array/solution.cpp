class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        auto compare = [](int &a, int &b) { return a > b; };
        priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);
        
        int n = nums.size();
        
        for (int i=0; i<n; i++) {
            pq.push(nums[i]);
            if (pq.size() > k) pq.pop();
        } 
        
        return pq.top();
    }
};