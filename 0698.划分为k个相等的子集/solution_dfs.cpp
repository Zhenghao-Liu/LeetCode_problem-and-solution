/*
* 要分为k组，那么每组的和自然是sum/k
* 剪枝1：sum%k!=0
  剪枝2: nums中最大的数比sum/k还大
* 回溯去试即可
*/
class Solution {
    vector<bool> use;
    int target;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=0;
        int max_nums=INT_MIN;
        for (int i:nums)
        {
            sum+=i;
            max_nums=max(max_nums,i);
        }
        target=sum/k;
        if (sum%k!=0 || max_nums>target)
            return false;
        int nums_size=nums.size();
        use=vector<bool>(nums_size,false);
        return dfs(nums,0,0,k);
    }
    bool dfs(vector<int> &nums,int cur,int start,int k)
    {
        if (k==0)
            return true;
        if (cur==target)
            return dfs(nums,0,0,k-1);
        int nums_size=nums.size();
        for (int i=start;i<nums_size;++i)
            if (!use.at(i) && cur+nums.at(i)<=target)
            {
                use.at(i)=true;
                if (dfs(nums,cur+nums.at(i),i+1,k))
                    return true;
                use.at(i)=false;
            }
        return false;
    }
};
