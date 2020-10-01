//模拟
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int index=0,max_nums=0;
        int size=nums.size();
        for (int i=0;i<size;++i)
            if (nums.at(i)>max_nums)
            {
                max_nums=nums.at(i);
                index=i;
            }
        for (int &i:nums)
            if (max_nums!=i && max_nums<i*2)
                return -1;
        return index; 
    }
};
