class Solution {
public:
    bool isMatch(string word, string pattern) {
        int n = word.length();
        unordered_map<char, char> mp;
        unordered_set<char> vis;
        
        for (int i=0; i<n; i++) {
            if (mp.find(word[i]) != mp.end()) {
                if (mp[word[i]] != pattern[i]) return false;
            } 
            else {
                if (vis.find(pattern[i]) != vis.end()) return false;
                mp[word[i]] = pattern[i];
                vis.insert(pattern[i]);
            }
        }
        
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ret;
        
        for (auto word : words) {
            if (isMatch(word, pattern)) ret.push_back(word);
        }
        
        return ret;
    }
};