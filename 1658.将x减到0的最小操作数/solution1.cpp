/*
 * 两端的和==x==数组的总和-数组中间部分的和
 * 转换过来就是 数组中间的和==数组的总和-x
 * 求中间和：twosum+前缀和
 */
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for (int i:nums)
            sum+=i;
        unordered_map<int,int> ump;
        ump[0]=-1;
        int prefix=0;
        int size=nums.size();
        if (sum==x)
            return size;
        int ans=-1;
        for (int i=0;i<size;++i)
        {
            prefix+=nums.at(i);
            //prefix-[]==sum-x
            int tar=prefix-sum+x;
            if (ump.find(tar)!=ump.end())
                ans=max(ans,i-ump.at(tar));
            if (ump.find(prefix)==ump.end())
                ump[prefix]=i;
        }
        if (ans==-1)
            return -1;
        return size-ans;
    }
};
