/*
 蛮多方法的(以下复杂度是单次操作)
1. vector的暴力insert erase，O(n)
2. deque的暴力insert erase，相比于vector稍微好一点，但是复杂度有个常数波动比较大O(n)
3. list然后遍历中点之后增删O(n)
4. list加一个中间节点的指针(迭代器)，可以降到O(1)
5. 两个deque模拟前半段和后半段，O(1)
 */
class FrontMiddleBackQueue {
    //r可以最多多l一个
    deque<int> l;
    deque<int> r;
    int l_size,r_size=0;
public:
    FrontMiddleBackQueue() {
        l.clear();
        r.clear();
        l_size=0;
        r_size=0;
    }
    
    void pushFront(int val) {
        l.push_front(val);
        ++l_size;
        check();
    }
    
    void pushMiddle(int val) {
        if (l_size==r_size)
        {
            r.push_front(val);
            ++r_size;
        }
        else
        {
            l.push_back(val);
            ++l_size;
        }
    }
    
    void pushBack(int val) {
        r.push_back(val);
        ++r_size;
        check();
    }
    
    int popFront() {
        if (l_size==0 && r_size==0)
            return -1;
        int ans=-1;
        if (l_size!=0)
        {
            --l_size;
            ans=l.front();
            l.pop_front();
        }
        else
        {
            --r_size;
            ans=r.front();
            r.pop_front();
        }
        check();
        return ans;
    }
    
    int popMiddle() {
        if (l_size==0 && r_size==0)
            return -1;
        int ans=-1;
        if (l_size==r_size)
        {
            --l_size;
            ans=l.back();
            l.pop_back();
        }
        else
        {
            --r_size;
            ans=r.front();
            r.pop_front();
        }
        return ans;
    }
    
    int popBack() {
        if (l_size==0 && r_size==0)
            return -1;
        --r_size;
        int ans=r.back();
        r.pop_back();
        check();
        return ans;
    }
    void check()
    {
        while (l_size!=r_size && r_size!=l_size+1)
        {
            if (l_size>r_size)
            {
                int n=l.back();
                l.pop_back();
                r.push_front(n);
                --l_size;
                ++r_size;
            }
            else if (l_size<r_size)
            {
                int n=r.front();
                r.pop_front();
                l.push_back(n);
                --r_size;
                ++l_size;
            }
        }
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
