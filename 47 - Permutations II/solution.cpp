class Solution {
public:
    vector<vector<int>> ans;
    unordered_set<string> st;
    
    string hashing(vector<int>& cur) {
        string val;
        for (auto c : cur) {
            val += to_string(c);
        }
        
        return val;
    } 
    void perm(int l, int r, vector<int>& cur) {
        if (l == r) {
            if (st.find(hashing(cur)) == st.end()) {
                ans.push_back(cur);
                st.insert(hashing(cur));
            }
            return;
        } 
        
        for (int i=l; i<=r; i++) {
            swap(cur[l], cur[i]);
            perm(l+1, r, cur);
            swap(cur[l], cur[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        perm(0, nums.size()-1, nums);
        return ans;
    }
};