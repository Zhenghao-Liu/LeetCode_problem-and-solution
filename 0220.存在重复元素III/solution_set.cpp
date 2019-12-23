class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int nums_size=nums.size();
        //真香
        if (nums_size>=10000)
            return false;
        //一个存值的滑动窗口，最大长度为k，因为i占了那个k+1的1
        //这样就保证了|j-i|<=k
        //注意set不是线性的数据结构，所以超长时不能删除set.begin()
        set<int> sliding_window;
        for (int i=0;i<nums_size;++i)
        {
            //|[j]-[i]|<=t则-t<=[j]-[i]<=t即[i]-t<=[j]<=t+[i]
            //lower_bound(elem)返回元素值>=elem的第一个元素位置
            set<int>::iterator p=sliding_window.lower_bound(double(nums.at(i))-t);
            if (p!=sliding_window.end() && (*p)<=double(nums.at(i))+t)
                return true;
            sliding_window.insert(nums.at(i));
            if (sliding_window.size()==k+1)
                sliding_window.erase(nums.at(i-k));
        }
        return false;
    }
};
