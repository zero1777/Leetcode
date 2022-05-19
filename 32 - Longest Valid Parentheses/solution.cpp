class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> stk;
        stk.push(-1);
        
        for (int i=0; i<s.length(); i++) {
            if (s[i] == ')') {
                if (stk.top() != -1 && s[stk.top()] == '(') {
                    stk.pop();
                    maxLen = max(maxLen, i - stk.top());
                }
                else stk.push(i);
            } 
            else stk.push(i); 
        }
        
        return maxLen;
    }
};