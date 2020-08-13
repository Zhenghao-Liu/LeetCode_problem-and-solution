//用哈希表记录该数该数出现了几次
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> count(nums_size+1);
        for (int i:nums)
            ++count.at(i);
        int lost_num=0,repeat_num=0;
        for (int i=1;i<=nums_size;++i)
            if (count.at(i)==2)
                repeat_num=i;
            else if (count.at(i)==0)
                lost_num=i;
        return {repeat_num,lost_num};
    }
};
