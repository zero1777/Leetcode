typedef pair<int, int> pr;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        pr ret;
        auto compare = [&matrix](pr a, pr b) { return matrix[a.first][a.second] > matrix[b.first][b.second]; };
        priority_queue<pr, vector<pr>, decltype(compare)> pq(compare);
        
        for (int i=0; i<n; i++) pq.push({i, 0});
        while (k--) {
            ret = pq.top();
            pq.pop();
            
            if (ret.second + 1 < n) pq.push({ret.first, ret.second + 1});
        }
        
        return matrix[ret.first][ret.second];
    }
};