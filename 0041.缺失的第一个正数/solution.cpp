class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int nums_size=nums.size(),positive_int_size=0;
        for (int i=0;i<nums_size;++i)
            ++positive_int_size;
        ++positive_int_size;
        vector<bool> judge(positive_int_size);
        judge.assign(positive_int_size,false);
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)<=0 || nums.at(i)>positive_int_size)
                continue;
            else
                judge.at(nums.at(i)-1)=true;
        for (int i=0;i<positive_int_size;++i)
            if (!judge.at(i))
                return i+1;
        return positive_int_size;
    }
};
