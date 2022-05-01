class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '#') sIdx = max(0, sIdx - 1);
            else {
                s[sIdx++] = s[i];
            }
        }
        
        int tIdx = 0;
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == '#') tIdx = max(0, tIdx - 1);
            else {
                t[tIdx++] = t[i];
            }
        }
        
        if (sIdx != tIdx) return false;
        else return s.compare(0, sIdx, t, 0, tIdx) == 0;
    }
};