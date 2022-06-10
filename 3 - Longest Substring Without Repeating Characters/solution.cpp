class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longestSubstr = 0;
        int left = 0;
        unordered_set<char> st;
        
        for (int i=0; i<s.length(); i++) {
            while (st.find(s[i]) != st.end()) {
                st.erase(s[left++]);
            } 
            st.insert(s[i]);
            
            longestSubstr = max(longestSubstr, i - left + 1);
        }
        
        return longestSubstr;
    }
};