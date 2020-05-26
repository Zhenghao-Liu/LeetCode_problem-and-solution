//方法同442.数组中重复的数据
//用自身做哈希，出现过的数字设为负数，那么最后为正数的就是消失的数字
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int nums_size=nums.size();
        for (int &i:nums)
        {
            int abs_i=abs(i);
            if (nums.at(abs_i-1)>0)
                nums.at(abs_i-1)*=-1;
        }
        vector<int> ans;
        for (int i=0;i<nums_size;++i)
            if (nums.at(i)>0)
                ans.push_back(i+1);
        return ans;
    }
};
