class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.length() < k) return false;
        unordered_set<string> st;
        
        for (int i=0; i<=s.length()-k; i++) {
            string code = s.substr(i, k);
            st.insert(code);
        }
        
        return st.size() == pow(2,k);
    }
};