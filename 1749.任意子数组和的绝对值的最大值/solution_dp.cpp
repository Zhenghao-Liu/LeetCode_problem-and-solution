/*
 * 因为是和的绝对值的最大
 * 设两个dp数组
   mx[i]表示以nums[i]为结尾的和的最大值
   mi[i]表示以nums[i]为结尾的和的最小值
 * 之后都扫一趟取绝对值，找到最大的结果即可
 */
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sz=nums.size();
        vector<int> mx(sz);
        vector<int> mi(sz);
        mx.at(0)=mi.at(0)=nums.at(0);
        for (int i=1;i<sz;i++) {
            mx.at(i)=max(nums.at(i),nums.at(i)+mx.at(i-1));
            mi.at(i)=min(nums.at(i),nums.at(i)+mi.at(i-1));
        }
        int ans=INT_MIN;
        for (int i:mx) {
            if (i>=0) {
                ans=max(ans,i);
            } else {
                ans=max(ans,-i);
            }
        }
        for (int i:mi) {
            if (i>=0) {
                ans=max(ans,i);
            } else {
                ans=max(ans,-i);
            }
        }
        return ans;
    }
};
