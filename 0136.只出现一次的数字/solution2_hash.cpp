/*
* 把数字存进哈希表中
* 若已经存在则删除
* 最后留下的一个即只出现一次的数字
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int nums_size=nums.size();
        unordered_map<int,int> nums_map;
        for (int i:nums)
            if (nums_map.find(i)==nums_map.end())
                nums_map.insert({i,1});
            else
                nums_map.erase(i);
        return nums_map.begin()->first;
    }
};
