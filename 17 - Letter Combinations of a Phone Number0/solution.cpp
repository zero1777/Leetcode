class Solution {
public:
    vector<string> dict = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return vector<string>();
        combFunc(digits, "", 0);
        return ans;
    }
    
    void combFunc(string &digits, string current, int idx) {
        if (idx == digits.size()) {
            ans.push_back(current);
            return ;
        }
        
        for (auto alphabet : dict[digits[idx] - '2']) {
            combFunc(digits, current + alphabet, idx+1);
        }
    }
};