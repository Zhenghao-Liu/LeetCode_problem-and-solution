//每进一个元素插入排序一次
class MedianFinder {
    vector<int> v;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        v.clear();
    }
    
    void addNum(int num) {
        if (v.empty())
            v.push_back(num);
        else
            v.insert(lower_bound(v.begin(),v.end(),num),num);
    }
    
    double findMedian() {
        int v_size=v.size();
        if (v_size%2!=0)
            return v.at(v_size/2);
        else
            return (v.at(v_size/2)+v.at(v_size/2-1))/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
