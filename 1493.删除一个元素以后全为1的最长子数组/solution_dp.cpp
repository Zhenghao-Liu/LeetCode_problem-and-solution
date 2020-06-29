//记录从头到尾连续的1有多少个和从尾到头连续的1有多少个，然后枚举删除一个元素，那么1的个数就是前面两者相加
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> begin_to_end(nums_size,0);
        for (int i=1;i<nums_size;++i)
            if (nums.at(i-1)==1)
                begin_to_end.at(i)=begin_to_end.at(i-1)+1;
        vector<int> end_to_begin(nums_size,0);
        for (int i=nums_size-2;i>=0;--i)
            if (nums.at(i+1)==1)
                end_to_begin.at(i)=end_to_begin.at(i+1)+1;
        int ans=INT_MIN;
        for (int i=0;i<nums_size;++i)
            ans=max(ans,begin_to_end.at(i)+end_to_begin.at(i));
        return ans;
    }
};
