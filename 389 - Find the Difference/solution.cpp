class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        
        for (auto c : s) ans ^= (c - 'a');
        for (auto c : t) ans ^= (c - 'a');
        
        return ans + 'a';
    }
};