/*
 * 显然，应该尽可能的去划分球
 * 二分枚举答案
 * 答案的下界是1，最少每个袋子有一个球
   答案的上界是nums中的最大值，即不去分袋子的球
 * 有一个特殊情况
 eg：袋子是9，枚举答案是3，那么需要9/3-1=2次划分操作
 eg：袋子是8，枚举答案是3，那么需要8/3=2次划分操作
 * 要么进行特判是否整除，要么(nums[i]-1)/mid
 */
class Solution {
public:
    int minimumSize(vector<int>& nums, int mx) {
        int l=1,r=*max_element(nums.begin(),nums.end());
        while (l<r) {
            int mid=l+(r-l)/2;
            int cnt=0;
            for (int i:nums) {
                if (i>mid) {
                    int tmp=i/mid;
                    if (i%mid==0) {
                        tmp--;
                    }
                    cnt+=tmp;
                    if (cnt>mx) {
                        break;
                    }
                }
            }
            if (cnt<=mx) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
};
