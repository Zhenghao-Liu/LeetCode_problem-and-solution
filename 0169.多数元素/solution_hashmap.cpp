//用哈希表建立起各个数字出现的次数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int half_size=nums.size()/2;
        unordered_map<int,int> nums_map;
        for (int& i:nums)
            if (nums_map.find(i)==nums_map.end())
                nums_map.insert({i,1});
            else
            {
                ++nums_map.at(i);
                if (nums_map.at(i)>half_size)
                    return i;
            }
        //防止只有一个元素的情况
        return nums.at(0);
    }
};
