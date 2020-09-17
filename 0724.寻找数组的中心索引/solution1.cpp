//枚举每个位置左边的和，以及右边的和
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> l_to_r(nums_size,0);
        for (int i=1;i<nums_size;++i)
            l_to_r.at(i)=l_to_r.at(i-1)+nums.at(i-1);
        vector<int> r_to_l(nums_size,0);
        for (int i=nums_size-2;i>=0;--i)
            r_to_l.at(i)=r_to_l.at(i+1)+nums.at(i+1);
        for (int i=0;i<nums_size;++i)
            if (l_to_r.at(i)==r_to_l.at(i))
                return i;
        return -1;
    }
};
