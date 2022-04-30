class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for (auto num : nums) {
            mp[num]++;
        }
        
        auto cmp = [&mp](int a, int b) { return mp[a] > mp[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (auto m : mp) {
            pq.push(m.first);
            if (pq.size() > k) pq.pop();
        }
        
        while (!pq.empty()) {
            ans.push_back(pq.top());
            pq.pop();
        }
        
        return ans;
    }
};