/*
* 采用集合unordered_set的方法
* [](https://blog.csdn.net/qq_32172673/article/details/85160180)
* 因为集合的查找效率较高
* 采取全都往小的方向找
* [1,2,3,4,5]那么1需要找0,2需要找0和1,3要找0和1和2，以此类推，最后遍历完则找到最长的连续序列
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set_nums;
        for (int i:nums)
            set_nums.insert(i);
        int answer=0,temp;
        for (int i:set_nums)
            if (set_nums.find(i+1)==set_nums.end())
            {
                temp=1;
                while (set_nums.find(i-temp)!=set_nums.end())
                    ++temp;
                if (answer<temp)
                    answer=temp;
            }
        return answer;
    }
};
