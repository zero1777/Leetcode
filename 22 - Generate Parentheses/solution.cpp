class Solution {
public:
    vector<string> ans;
    string str = "";
    void generate(int n, int left, int right) {
        if (right == n) {
            ans.push_back(str);
            return ;
        }
        
        if (left < n) {
            str.push_back('(');
            generate(n, left + 1, right);
            str.pop_back();
        }
        
        if (right < left) {
            str.push_back(')');
            generate(n, left, right + 1);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n, 0, 0);
        return ans;
    }
};