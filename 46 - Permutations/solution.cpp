class Solution {
public:
    vector<vector<int>> ans;
    void perm(int l, int r, vector<int>& cur) {
        if (l == r) ans.push_back(cur);
        
        for (int i=l; i<=r; i++) {
            swap(cur[l], cur[i]);
            perm(l+1, r, cur);
            swap(cur[l], cur[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        perm(0, nums.size()-1, nums);
        return ans;
    }
};