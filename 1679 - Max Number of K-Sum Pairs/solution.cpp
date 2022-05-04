class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (auto num : nums) mp[num]++;
        
        int sum = 0;
        for (auto &it : mp) {
            int num = k - it.first;
            if (num == it.first) sum += it.second / 2;
            else if (mp.find(num) != mp.end()) sum += min(mp[num], it.second);
            it.second = 0;
        }
        
        return sum;
    }
};