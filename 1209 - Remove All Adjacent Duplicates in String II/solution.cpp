class Solution {
public:
    #define pi pair<char, int>
    string removeDuplicates(string s, int k) {
        deque<pi> dq;
        for (auto st : s) {
            if (!dq.empty() && dq.back().first == st) {
                dq.back().second += 1;
                if (dq.back().second % k == 0) dq.pop_back();
            } else {
                dq.push_back({st, 1});      
            }
        }
        
        string ans;
        for (auto [c, n] : dq) {
            while (n--) ans.push_back(c);
        }
        
        return ans;
    }
};