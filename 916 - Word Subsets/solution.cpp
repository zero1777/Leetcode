class Solution {
public:
    bool isSubset(string word, vector<int> freq) {
        for (auto w : word) freq[w - 'a']--;
        for (int i=0; i<26; i++) if (freq[i] > 0) return false;
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ret;
        vector<int> freq(26, 0);
        for (auto word : words2) {
            vector<int> tmp(26, 0);
            for (auto w : word) tmp[w - 'a']++; 
            for (int i=0; i<26; i++) freq[i] = max(freq[i], tmp[i]);
        }
        
        for (auto word : words1) {
            if (isSubset(word, freq)) ret.push_back(word);
        }
        
        return ret;
    }
};