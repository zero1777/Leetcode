class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int longestStr = 0;
        unordered_map<string, int> dp;
        
        auto compare = [](const string a, const string b) { return a.length() < b.length(); };
        sort(words.begin(), words.end(), compare);
        
        for (auto word : words) {
            dp[word] = 1;
            for (int i = 1; i <= word.length(); i++) {
                string pre = word.substr(0, i - 1) + word.substr(i, word.length() - i);
                if (dp.find(pre) != dp.end()) {
                    dp[word] = max(dp[word], dp[pre] + 1);    
                }
            }
            longestStr = max(longestStr, dp[word]);
        }
        
        return longestStr;
    }
};