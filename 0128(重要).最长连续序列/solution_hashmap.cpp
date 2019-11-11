/*
* 采用哈希表unordered_map
* [](https://www.cnblogs.com/slothrbk/p/8823092.html)
* 采取哈希表形式存取连续的长度
* 只需要对连续序列的两端更新值即可
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash_nums;
        int left,right,answer=0,temporary;
        for (int num_i:nums)
            if (hash_nums.find(num_i)==hash_nums.end())
            {
                left=hash_nums.find(num_i-1)!=hash_nums.end()?hash_nums.at(num_i-1):0;
                right=hash_nums.find(num_i+1)!=hash_nums.end()?hash_nums.at(num_i+1):0;
                temporary=left+right+1;
                //只需对连续的两端改值就好
                //[0,1,2,3]当操作到"3"时只需要改"3"和"0"的值就可以
                if (hash_nums.find(num_i-left)!=hash_nums.end())
                    hash_nums.at(num_i-left)=temporary;
                if (hash_nums.find(num_i+right)!=hash_nums.end())
                    hash_nums.at(num_i+right)=temporary;
                hash_nums[num_i]=temporary;
                if (1+left+right>answer)
                    answer=1+left+right;
            }
        return answer;
    }
};
