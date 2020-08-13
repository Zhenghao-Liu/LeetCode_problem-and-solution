//先排序后模拟检查
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int nums_size=nums.size();
        int repeat_num=0;
        int lost_num=0;
        for (int i=1;i<nums_size;++i)
        {
            if (nums.at(i)==nums.at(i-1))
                repeat_num=nums.at(i);
            else if (nums.at(i)!=nums.at(i-1)+1)
                lost_num=nums.at(i-1)+1;
        }
        if (lost_num==0)
        {
            if (nums.back()==nums_size)
                lost_num=1;
            else
                lost_num=nums_size;
        }
        return {repeat_num,lost_num};
    }
};
