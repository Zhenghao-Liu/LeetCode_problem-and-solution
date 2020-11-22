//因为都是正数，所以可以用滑窗，如果是有负数，需要用到前缀和+双端队列
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int size=nums.size();
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum<x)
            return -1;
        int tar=sum-x;
        int r=-1;
        int ans=-1;
        int win=0;
        for (int l=-1;r+1<size;++l)
        {
            if (l>-1)
                win-=nums.at(l);
            while (win<tar && r+1<size)
            {
                ++r;
                win+=nums.at(r);
            }
            if (win==tar)
                ans=max(ans,r-l);
        }
        return ans==-1 ? -1 : size-ans;
    }
};
