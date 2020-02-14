//采用两个优先队列存小半部分和大半部分
class MedianFinder {
private:
    //小半部分是大顶堆，从大到小
    priority_queue <int,vector<int>,less<int>> low;
    //大半部分是小顶堆，从小到大
    priority_queue <int,vector<int>,greater<int>> high;
public:
    /** initialize your data structure here. */
    MedianFinder() {

        }
    
    void addNum(int num) {
        //默认low可以比high多存一个元素
        low.push(num);
        high.push(low.top());
        low.pop();
        if (low.size()<high.size())
        {
            low.push(high.top());
            high.pop();
        }
    }
    
    double findMedian() {
        if (low.size()>high.size())
            return low.top();
        return (low.top()+high.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
