/*
* 采用两个栈
* 一个就是常规的栈，一个是记录最小值得栈
* 把记录最小值的栈，用动态规划思想，看成是前i个数时对应的最小值
*/
class MinStack {
    stack<int> stack_m;
    stack<int> dp_min;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stack_m.push(x);
        if (dp_min.empty() || x<dp_min.top())
            dp_min.push(x);
        else
            dp_min.push(dp_min.top());
    }
    
    void pop() {
        stack_m.pop();
        dp_min.pop();
    }
    
    int top() {
        return stack_m.top();
    }
    
    int getMin() {
        return dp_min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
