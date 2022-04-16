class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int residual, int start, int sz, int k, vector<int>& cur) {
        if (residual < 0) return ;
        if (residual == 0 && sz == k) {
            ans.push_back(cur);
            return ;
        }
        
        for (int i = start; i <= 9; ++i) {
            cur.push_back(i);
            solve(residual - i, i + 1, sz + 1, k, cur);
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> init = vector<int>();
        solve(n, 1, 0, k, init); 
        return ans;     
    }
};