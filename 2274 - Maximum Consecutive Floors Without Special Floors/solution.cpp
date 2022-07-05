class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        set<int> st;
        int maxCsc = -1;
        
        st.insert(top + 1);
        for (auto s : special) st.insert(s);
        
        for (auto s : st) {
            maxCsc = max(maxCsc, s - bottom);
            bottom = s + 1;
        }
        
        return maxCsc;
    }
};