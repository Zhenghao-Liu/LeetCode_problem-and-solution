/*
* 这次是一个环
* 打劫了第一家最后一家就不能打劫
* 打劫了最后一家第一家就不能打劫
* 那就分两次dp
* 第一次dp[0,n-1]
* 第二次dp[1,n]
* 取最大值即可
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size==0)
            return 0;
        else if (nums_size==1)
            return nums.at(0);
        else if (nums_size==2)
            return max(nums.at(0),nums.at(1));
        vector<int> dp_no_last(nums_size-1);
        dp_no_last.at(0)=nums.at(0);
        dp_no_last.at(1)=max(nums.at(0),nums.at(1));
        for (int i=2;i<nums_size-1;++i)
            dp_no_last.at(i)=max(dp_no_last.at(i-1),dp_no_last.at(i-2)+nums.at(i));
        vector<int> dp_no_first(nums_size);
        dp_no_first.at(nums_size-1)=nums.at(nums_size-1);
        dp_no_first.at(nums_size-2)=max(nums.at(nums_size-1),nums.at(nums_size-2));
        for (int i=nums_size-3;i>0;--i)
            dp_no_first.at(i)=max(dp_no_first.at(i+1),dp_no_first.at(i+2)+nums.at(i));
        return max(dp_no_last.at(nums_size-2),dp_no_first.at(1));
    }
};
