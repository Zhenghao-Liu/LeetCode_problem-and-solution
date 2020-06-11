/*
* 只考虑二进制下一位数的情况
  设有t个1，n-t个0，那么他们的汉明距离
  对于每个1来说，汉明距离是n-t，那么现在有t个1，
  即总的汉明距离是t*(n-t)
* 可以把所有nums分成一位一位来看
  把所有nums的第i位汉明距离求出来最后再相加即可
  即所有数对齐，不足高位补0即可，所有数的第i位为一组处理
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        vector<int> count_one(32,0);
        for (int i:nums)
        {
            int j=0;
            while (i!=0)
            {
                count_one.at(j)+=(i&1);
                ++j;
                i>>=1;
            }
        }
        int ans=0;
        for (int &t:count_one)
            ans+=t*(n-t);
        return ans;
    }
};
