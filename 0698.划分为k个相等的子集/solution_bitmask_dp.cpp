/*
* 可以对nums的每一位进行状压，0表示未选取，1表示选取了
* 转移条件：当前状态是i，要转移到状态nxt，
  即新加入的数字是nums[j]，即nxt=i|(1<<j)
  前提是状态i时已经取的数字的总和cur_sum[i]，除去满足分组的一部分后，剩下未构成一个完整分组的部分，即cur_sum[i]%target
  且当前要取的数字nums[j]不能和cur_sum[i]%target超出target的部分
  即nums.at(j)+(cur_sum.at(i)%target)<=target
*/
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k==1)
            return true;
        int nums_size=nums.size();
        sort(nums.begin(),nums.end());
        int sum=0;
        for (int i:nums)
            sum+=i;
        int target=sum/k;
        //剪枝
        if (sum%k!=0 || nums.back()>target)
            return false;
        //全集
        int ALL=(1<<nums_size)-1;
        vector<bool> dp(ALL+1,false);
        dp.at(0)=true;
        vector<int> cur_sum(ALL+1,0);
        for (int i=0;i<=ALL;++i)
        {
            if (!dp.at(i))
                continue;
            for (int j=0;j<nums_size;++j)
            {
                if ((i&(1<<j))!=0)
                    continue;
                int nxt=i|(1<<j);
                //不同状态转移到同一个状态nxt，他们最后cur_sum[nxt]都是一样的，所以没必要重新计算
                if (dp.at(nxt))
                    continue;
                if (nums.at(j)+(cur_sum.at(i)%target)<=target)
                {
                    dp.at(nxt)=true;
                    cur_sum.at(nxt)=cur_sum.at(i)+nums.at(j);
                }
                //因为提前按照升序排列，剪枝
                else
                    break;
            }
        }
        return dp.at(ALL);
    }
};
