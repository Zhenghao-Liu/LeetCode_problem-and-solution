//只用存奇数的位置即可，因为奇数位置差即中间偶数的个数
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int nums_size=nums.size();
        vector<int> odd_index{-1};
        for (int i=0;i<nums_size;++i)
            if ((nums.at(i)&1)==1)
                odd_index.push_back(i);
        odd_index.push_back(nums.size());
        int odd_index_size=odd_index.size();
        if (odd_index_size-2<k)
            return 0;
        int ans=0;
        int left=1,right=left+k-1;
        while (right+1<odd_index_size)
        {
            ans+=(odd_index.at(left)-odd_index.at(left-1))*(odd_index.at(right+1)-odd_index.at(right));
            ++left;
            ++right;
        }
        return ans;
    }
};
