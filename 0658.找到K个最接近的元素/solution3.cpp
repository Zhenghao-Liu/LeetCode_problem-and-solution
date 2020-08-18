/*
* 方法类似solution2
* 先二分找到>=x的作为right，right-1作为left
* 然后双指针比较差值移动，此时双指针其实就是ans.begin()-1和ans.end()
* 且arr本身就是有序的所以不用排序，且不用多一个数组
* 最后根据双指针范围返回即可
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int arr_size=arr.size();
        if (k==arr_size)
            return arr;
        int r=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int l=r-1;
        while (l>=0 && r<arr_size && r-l-1<k)
        {
            int l_diff=abs(x-arr.at(l));
            int r_diff=abs(x-arr.at(r));
            if (l_diff<=r_diff)
                --l;
            else
                ++r;
        }
        if (r-l-1<k)
        {
            while (l>=0 && r-l-1<k)
                --l;
            while (r<arr_size && r-l-1<k)
                ++r;
        }
        return vector<int>(arr.begin()+l+1,arr.begin()+r);
    }
};
