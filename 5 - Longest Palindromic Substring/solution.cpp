class Solution {
public:
    int compare(string &str, int left, int right) {
        int n = str.length();
        while (left >= 0 && right < n) {
            if (str[left] != str[right]) break;
            left--; right++;
        }
        
        return right - left - 1;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        pair<int, int> maxLen = {0, 1};
        
        for (int i=0; i<n-1; i++) {
            int a1 = compare(s, i, i);
            int a2 = compare(s, i, i+1);
            
            int a = max(a1, a2);
            if (maxLen.second < a) {
                maxLen = {i - (a-1) / 2, a};
            }
        } 
        
        return s.substr(maxLen.first, maxLen.second);
    }
};