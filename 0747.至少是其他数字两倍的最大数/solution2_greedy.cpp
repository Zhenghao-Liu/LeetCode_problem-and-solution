//直接找最大的和第二大的去比较即可
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int nums_size=nums.size();
        if (nums_size<=1)
            return 0;
        int max_nums=0,second_max=0;
        int max_index=0;
        for (int i=0;i<nums_size;++i)
        {
            int ii=nums.at(i);
            if (ii>max_nums)
            {
                second_max=max_nums;
                max_index=i;
                max_nums=ii;
            }
            else if (ii>=second_max)
                second_max=ii;
        }
        return max_nums>=second_max*2 ? max_index : -1;
    }
};
