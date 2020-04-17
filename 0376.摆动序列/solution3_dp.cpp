//方法和solution2一样优化了内存
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<2)
            return nums_size;
        //up是前i个元素中，摆动序列以上升元素结尾的最长子序列长度
        //down是前i个元素中，摆动序列以下降元素结尾的最长子序列长度
        int up=1,down=1;
        for (int i=1;i<nums_size;++i)
            if (nums.at(i)>nums.at(i-1))
                up=down+1;
            else if (nums.at(i)<nums.at(i-1))
                down=up+1;
        return max(up,down);
    }
};
