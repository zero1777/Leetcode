class Solution {
public:
    int removePalindromeSub(string s) {
        int n = s.length() - 1;
        for (int i=0, j=n; i<n && j>=0; i++, j--) {
            if (s[i] != s[j]) return 2;
        }
        
        return 1;
    }
};