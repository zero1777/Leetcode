class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> init = vector<int>();
        solve(candidates, target, 0, init);
        return ans;
    }
    void solve(vector<int>& candidates, int residual, int start, vector<int>& cur) {
        if (residual < 0) return ;
        if (residual == 0) {
            ans.push_back(cur);
            return ;
        }
        
        for (int i=start; i<candidates.size(); i++) {
            int num = candidates[i];
            int times = residual / num;
            for (int j=1; j<=times; j++) {
                cur.push_back(num);
                solve(candidates, residual - num*j, i+1, cur);
            }
            while (times--) cur.pop_back();
        }
    }
};