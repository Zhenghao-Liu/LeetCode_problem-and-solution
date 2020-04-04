/*
* 当我们从左往右处理到left下标时，左边的最大值left_max对它而言是可信的，但right_max对它而言是不可信的。
  当我们从右往左处理到right下标时，右边的最大值right_max对它而言是可信的，但left_max对它而言是不可信的。
  因为是从两边往中间走，中间是高是低不确定，只能确定两端
* 对于位置left而言，它左边最大值一定是left_max，右边最大值“大于等于”right_max，这时候，如果left_max<right_max成立，那么它就知道自己能存多少 水了。无论右边将来会不会出现更大的right_max，都不影响这个结果。 所以当left_max<right_max时，我们就希望去处理left下标，反之，我们希望去处理right下标。
*/
class Solution {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1;
        int left_max=0,right_max=0;
        int ans=0;
        while (left<=right)
            if (left_max<right_max)
            {
                ans+=max(0,left_max-height.at(left));
                left_max=max(left_max,height.at(left));
                ++left;
            }
            else
            {
                ans+=max(0,right_max-height.at(right));
                right_max=max(right_max,height.at(right));
                --right;
            }
        return ans;
    }
};
