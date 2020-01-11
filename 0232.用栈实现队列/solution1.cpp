class MyQueue {
private:
    stack<int> s;
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> helper;
        while (!s.empty())
        {
            helper.push(s.top());
            s.pop();
        }
        int answer=helper.top();
        helper.pop();
        while (!helper.empty())
        {
            s.push(helper.top());
            helper.pop();
        }
        return answer;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> helper;
        while (!s.empty())
        {
            helper.push(s.top());
            s.pop();
        }
        int answer=helper.top();
        while (!helper.empty())
        {
            s.push(helper.top());
            helper.pop();
        }
        return answer;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
