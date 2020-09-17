/*
* 复杂度nlogn的话采用二分
* 因为最小距离是0，最大距离是最大的数-最小的数
  所以可以二分答案
* 先排序nums
* 二分答案，得出可能答案mid
  然后用双指针方法计算出距离对数小于等于mid的组数cnt
  即满足nums[right]-nums[left]<=mid left<right的所有可能
  因为已经按照升序排序，随着right增大，被减数nums[right]也增大
  要想满足不等式，减数nums[left]也要增大
* 若cnt<k，则表明可能答案过小，l=mid+1
  否则r=mid
*/
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.back()-nums.at(0);
        int nums_size=nums.size();
        while (l<r)
        {
            int mid=l+(r-l)/2;
            int cnt=0;
            int left=0;
            for (int right=0;right<nums_size;++right)
            {
                while (left<right && nums.at(right)-nums.at(left)>mid)
                    ++left;
                cnt+=right-left;
            }
            if (cnt<k)
                l=mid+1;
            else
                r=mid;
        }
        return l;
    }
};
