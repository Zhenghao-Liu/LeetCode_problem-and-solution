/*
* 差值最小，那么先二分找到第一个>=x的元素位置作为right，right-1作为left
* 之后双指针比较差值中心向两端拓展，并放入ans中
* 注意越界和长度已经到达k情况
* 最后单独排序ans即可
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int arr_size=arr.size();
        if (k==arr_size)
            return arr;
        int r=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l=r-1;
        vector<int> ans;
        while (l>=0 && r<arr_size && ans.size()<k)
        {
            int l_diff=abs(x-arr.at(l));
            int r_diff=abs(x-arr.at(r));
            if (l_diff<=r_diff)
            {
                ans.push_back(arr.at(l));
                --l;
            }
            else
            {
                ans.push_back(arr.at(r));
                ++r;
            }
        }
        if (ans.size()<k)
        {
            while (l>=0 && ans.size()<k)
            {
                ans.push_back(arr.at(l));
                --l;
            }
            while (r<arr_size && ans.size()<k)
            {
                ans.push_back(arr.at(r));
                ++r;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
