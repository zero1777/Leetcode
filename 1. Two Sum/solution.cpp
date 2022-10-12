class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int n = nums.size();
        
        for (int i=0; i<n; i++) mp[nums[i]] = i;
        for (int i=0; i<n; i++) {
            int res = target - nums[i];
            cout << i << endl;
            if (mp.find(res) != mp.end() && mp[res] != i) {
                vector<int> vec = {i, mp[res]};
                return vec;
            }
        }
        
        return vector<int>();
    }
};