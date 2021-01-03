//一个栈用来插入元素，一个通过出栈再入新栈的方式达到反序，进而用新栈来达到出队的效果
class CQueue {
    stack<int> s;
    stack<int> s_queue;
public:
    CQueue() {
        while (!s.empty())
            s.pop();
        while (!s_queue.empty())
            s_queue.pop();
    }
    
    void appendTail(int value) {
        s.push(value);
    }
    
    int deleteHead() {
        if (s.empty() && s_queue.empty())
            return -1;
        if (!s_queue.empty())
        {
            int ans=s_queue.top();
            s_queue.pop();
            return ans;
        }
        while (!s.empty())
        {
            int n=s.top();
            s.pop();
            s_queue.push(n);
        }
        return this->deleteHead();
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
