class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> mp;
        
        for (auto str : strs) {
            string ori = str;
            sort(str.begin(), str.end());
            mp[str].push_back(ori);
        }
        
        ret.reserve(mp.size());
        for (auto m : mp) ret.push_back(m.second);
        
        return ret;
    }
};