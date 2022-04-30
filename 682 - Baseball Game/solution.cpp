class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for (auto op : ops) {
            if (op == "+") {
                int preVal = stk.top();
                stk.pop();
                
                int val = preVal + stk.top();
                stk.push(preVal);
                stk.push(val);
            } else if (op == "C") {
                stk.pop();
            } else if (op == "D") {
                stk.push(stk.top() * 2);
            } else {
                stk.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }

        return sum;
    }
};