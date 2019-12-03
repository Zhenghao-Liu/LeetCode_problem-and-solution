/*
* 摩尔投票法：出现最多元素出现的次数一定大于其他所有元素出现次数之和
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int nums_size=nums.size(),answer=nums.at(0),count=1;
        for (int i=1;i<nums_size;++i)
            if (count==0)
            {
                answer=nums.at(i);
                ++count;
            }
            else
                answer==nums.at(i)?++count:--count;
        return answer;
    }
};
