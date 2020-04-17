class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<2)
            return nums_size;
        //up[i]是前i个元素中，摆动序列以上升元素结尾的最长子序列长度
        vector<int> up(nums_size,1);
        //down[i]是前i个元素中，摆动序列以下降元素结尾的最长子序列长度
        vector<int> down(nums_size,1);
        for (int i=1;i<nums_size;++i)
            if (nums.at(i)>nums.at(i-1))
            {
                up.at(i)=down.at(i-1)+1;
                down.at(i)=down.at(i-1);
            }
            else if (nums.at(i)<nums.at(i-1))
            {
                down.at(i)=up.at(i-1)+1;
                up.at(i)=up.at(i-1);
            }
            else
            {
                up.at(i)=up.at(i-1);
                down.at(i)=down.at(i-1);
            }
        return max(up.at(nums_size-1),down.at(nums_size-1));
    }
};
