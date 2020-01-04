class MyStack {
private:
    queue<int> q;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp,q_size=q.size();
        while (q_size>1)
        {
            temp=q.front();
            q.pop();
            q.push(temp);
            --q_size;
        }
        temp=q.front();
        q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        int temp,q_size=q.size();
        while (q_size>0)
        {
            temp=q.front();
            q.pop();
            q.push(temp);
            --q_size;
        }
        return temp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
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
