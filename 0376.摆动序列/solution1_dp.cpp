class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<2)
            return nums_size;
        //up[i]表以nums[i]为结尾的摆动上升序列的(即该序列上一个元素<nums[i])最长长度是多少
        vector<int> up(nums_size,1);
        //down[i]表以nums[i]为结尾的摆动下降序列的(即该序列上一个元素>nums[i])最长长度是多少
        vector<int> down(nums_size,1);
        for (int i=1;i<nums_size;++i)
            for (int j=0;j<i;++j)
                if (nums.at(j)<nums.at(i))
                    up.at(i)=max(up.at(i),1+down.at(j));
                else if (nums.at(j)>nums.at(i))
                    down.at(i)=max(down.at(i),1+up.at(j));
        int ans=INT_MIN;
        for (int i=0;i<nums_size;++i)
            ans=max(ans,max(up.at(i),down.at(i)));
        return ans;
    }
};
