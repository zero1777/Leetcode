class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        
        for (int i=0; i<n; i++) {
            int left, right;
            
            // odd
            left = right = i;
            while (left >= 0 && right < n) {
                if (s[left] != s[right]) break;
                left--;  right++;
                cnt++;
            }
            
            // even
            left = i; right = i + 1;
            while (left >= 0 && right < n) {
                if (s[left] != s[right]) break;
                left--;  right++;
                cnt++;
            }
        }
        
        return cnt;
    }
};