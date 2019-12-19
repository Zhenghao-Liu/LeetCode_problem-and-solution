class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //升序的优先队列
        priority_queue <int,vector<int>,greater<int> > ascending;
        for (int &i:nums)
        {
            ascending.push(i);
            if (ascending.size()>k)
                ascending.pop();
        }
        return ascending.top();
    }
};
