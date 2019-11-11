/*
* 方法同gather1
* 采用库函数unordered_set.count(key),作用类似于at()但如果对应key时返回0
* 查找效率高于find为o(1)
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_nums;
        for (int i:nums)
            set_nums.insert(i);
        int answer=0,temp;
        for (int i:set_nums)
            if (!set_nums.count(i+1))
            {
                temp=1;
                while (set_nums.count(i-temp))
                    ++temp;
                if (answer<temp)
                    answer=temp;
            }
        return answer;
    }
};
