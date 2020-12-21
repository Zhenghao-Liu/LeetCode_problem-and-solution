/*
 * 首先说明了有序数组
 * 从左到右的过程中，对于[i]和[i-1]
   [i]与右边所有元素的绝对值之差在减小
   [i]与左边所有元素的绝对值之差在增大
 * 且有序数组，即绝对值之差是可以确定顺序是右边元素减左边元素，找好规律即可
 */
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int size=nums.size();
        vector<int> ans(size);
        int pre=0;
        int suf=0;
        for (int i=1;i<size;++i)
            ans.at(0)+=nums.at(i)-nums.at(0);
        suf=ans.at(0);
        for (int i=1;i<size;++i)
        {
            suf-=(nums.at(i)-nums.at(i-1))*(size-i);
            pre+=(nums.at(i)-nums.at(i-1))*i;
            ans.at(i)=suf+pre;
        }
        return ans;
    }
};
