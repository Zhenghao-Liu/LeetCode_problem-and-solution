//求出总和，以及每个位置左边的和，即可求出每个位置右边的和
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.empty())
            return -1;
        int nums_size=nums.size();
        vector<int> l_to_r(nums_size,0);
        int sum=nums.at(0);
        for (int i=1;i<nums_size;++i)
        {
            sum+=nums.at(i);
            l_to_r.at(i)=l_to_r.at(i-1)+nums.at(i-1);
        }
        for (int i=0;i<nums_size;++i)
            if (l_to_r.at(i)==sum-l_to_r.at(i)-nums.at(i))
                return i;
        return -1;
    }
};
