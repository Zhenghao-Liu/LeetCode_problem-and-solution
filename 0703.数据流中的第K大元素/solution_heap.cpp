class KthLargest {
    int max_size;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        max_size=k;
        while(!pq.empty())
            pq.pop();
        for (int i:nums)
        {
            pq.push(i);
            if (pq.size()>max_size)
                pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size()>max_size)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
