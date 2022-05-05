class MyStack {
public:
    queue<int> qu;
    MyStack() {
        
    }
    
    void push(int x) {
        int sz = qu.size();
        qu.push(x);
        while (sz--) {
            qu.push(qu.front());
            qu.pop();
        }
    }
    
    int pop() {
        int val = qu.front();
        qu.pop();
        return val;
    }
    
    int top() {
        return qu.front(); 
    }
    
    bool empty() {
        return qu.empty(); 
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */