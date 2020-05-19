/**
* 常规前缀和是先在prefix前面预存一个0，然后数组[a,b]的和即
  prefix[b+1]-prefix[a]
* 对于本题就是prefix[b+1]-prefix[a]==k
* 那换位就是prefix[a]=prefix[b+1]-k
* 对于本题我们从左往右遍历即求了prefix[b+1]可用单个变量prefix存即可
* 我们只关心和为k的个数即等式成立的次数
* 可以把前面算过的prefix用哈希表存起来，key是值，value是出现了多少次
* 即对于当前prefix[b+1]即prefix符合等式的
  即哈希表中helper[prefix[b+1]-k]即helper[prefix-k]的个数有多少个
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int prefix=0;
        int nums_size=nums.size();
        //key=前面的前缀和的值
        //value=这个数值出现了多少次
        unordered_map<int,int> helper;
        helper.insert({0,1});
        int ans=0;
        for (int i=0;i<nums_size;++i)
        {
            prefix+=nums.at(i);
            if (helper.find(prefix-k)!=helper.end())
                ans+=helper.at(prefix-k);
            ++helper[prefix];
        }
        return ans;
    }
};
