/*
* 首先注意k为0的情况，因为k为0不能做除数
  且是非负数，即k为0，且长度至少为2，表明最少有两个连续的0的才能满足
* k不为0的情况
  (prefix[j]-prefix[i])%k==0即prefix[j]%k==prefix[i]%k
  所以只用存前缀和求余后的结果
  但是有个问题是长度要至少为2，那么存结果不能求长度
  所以让求余后结果作为key，而第一次出现该结果的位置作为value
  为什么是第一次出现的位置呢，因为prefix[j]-prefix[i]，即j是当前，i当然是越左越能满足长度至少为2
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int nums_size=nums.size();
        if (nums_size<2)
            return false;
        if (k==0)
        {
            for (int i=1;i<nums_size;++i)
                if (nums.at(i)==0 && nums.at(i-1)==0)
                    return true;
        }
        else
        {
            unordered_map<int,int> prefix_index;
            prefix_index.insert({0,-1});
            int prefix=0;
            for (int i=0;i<nums_size;++i)
            {
                prefix+=nums.at(i);
                prefix%=k;
                if (prefix_index.find(prefix)!=prefix_index.end())
                {
                    if (i-prefix_index.at(prefix)>=2)
                        return true;
                }
                else
                    prefix_index[prefix]=i;
            }
        }
        return false;
    }
};
