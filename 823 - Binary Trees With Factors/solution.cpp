class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        sort(arr.begin(), arr.end()); 
        
        unordered_map<int, long> mp;
        for (auto num : arr) mp[num] = 1;
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (arr[i] % arr[j] == 0) {
                    int div = arr[i] / arr[j];
                    if (mp.find(div) != mp.end()) {
                        mp[arr[i]] += mp[arr[j]] * mp[div];
                        mp[arr[i]] %= mod;
                    }
                } 
            }
        }
        
        int ret = 0;
        for (auto m : mp) {
            ret += m.second;
            ret %= mod;
        }
        
        return ret;
    }
};