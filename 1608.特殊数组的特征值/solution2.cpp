//枚举可能的答案，之后用后缀和方式求得
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> cnt(nums_size+1,0);
        for (int i:nums)
            ++cnt.at(min(i,nums_size));
        int count=0;
        for (int i=nums_size;i>0;--i)
        {
            count+=cnt.at(i);
            if (count==i)
                return i;
        }
        return -1;
    }
};
