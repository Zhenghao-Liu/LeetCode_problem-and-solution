/*
* length[i]表示以nums[i]结尾的最长递增序列的长度
* count[i]表示以nums[i]结尾的最长递增序列有多少个序列
* 上述说的最长序列都是以处理到nums[i]为止，且初始化都为1，因为单个元素就是一个序列
* 所以最后求nums的最长递增序列，要先遍历length求出最长递增序列的长度
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int nums_size=nums.size();
        vector<int> length(nums_size,1);
        vector<int> count(nums_size,1);
        for (int j=1;j<nums_size;++j)
            for (int i=0;i<j;++i)
                if (nums.at(i)<nums.at(j))
                {
                    if (length.at(i)>=length.at(j))
                    {
                        length.at(j)=length.at(i)+1;
                        count.at(j)=count.at(i);
                    }
                    else if (length.at(i)+1==length.at(j))
                    {
                        count.at(j)+=count.at(i);
                    }
                }
        int max_length=1;
        for (int i:length)
            max_length=max(max_length,i);
        int ans=0;
        for (int i=0;i<nums_size;++i)
            if (length.at(i)==max_length)
                ans+=count.at(i);
        return ans;
    }
};
