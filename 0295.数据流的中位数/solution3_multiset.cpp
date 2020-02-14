class MedianFinder {
private:
    //借用multiset自动排序[multiset](https://www.cnblogs.com/ChinaHook/p/6985444.html)
    multiset<int> helper;
    //采用两个指针指向中位数，指针指向值不会改变，但左右连接的值可能变化,即mutliset排序的是地址之间联系变
    //对于同样元素，新值会插入在同样的值的后边
    //当size为奇数时low_p,high_P应指向同一个，size为偶数时low_p,high_P指向两个中间的数
    multiset<int>::iterator low_p,high_p;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        helper.clear();
        low_p=high_p=helper.end();
    }
    
    void addNum(int num) {
        int helper_size=helper.size();
        helper.insert(num);
        if (helper_size==0)
            low_p=high_p=helper.begin();
        //原先长度为奇数，即low_p,high_P应指向同一个
        else if (helper_size%2!=0)
        {
            if (num>=*low_p)
                ++high_p;
            else
                --low_p;
        }
        //原先长度为偶数
        else
        {
            if (num>=*low_p && num<*high_p)
            {
                ++low_p;
                --high_p;
            }
            else if (num<*low_p)
                --high_p;
            else
                ++low_p;
        }
    }
    
    double findMedian() {
        return (*low_p+*high_p)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
