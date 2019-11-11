//方法同1，采用.count(key)，优化查找效率
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash_nums;
        int left,right,answer=0,temporary;
        for (int num_i:nums)
            if (hash_nums.find(num_i)==hash_nums.end())
            {
                left=hash_nums.count(num_i-1)?hash_nums.at(num_i-1):0;
                right=hash_nums.count(num_i+1)?hash_nums.at(num_i+1):0;
                temporary=left+right+1;
                if (hash_nums.count(num_i-left))
                    hash_nums.at(num_i-left)=temporary;
                if (hash_nums.count(num_i+right))
                    hash_nums.at(num_i+right)=temporary;
                hash_nums[num_i]=temporary;
                if (1+left+right>answer)
                    answer=1+left+right;
            }
        return answer;
    }
};
