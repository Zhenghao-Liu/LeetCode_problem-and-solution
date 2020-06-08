class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size()<4)
            return false;
        //重要剪枝
        sort(nums.rbegin(),nums.rend());
        long long sum=0;
        for (int &i:nums)
            sum+=i;
        if (sum%4!=0)
            return false;
        long long target=sum/4;
        return dfs(nums,0,0,0,0,0,target);
    }
    bool dfs(vector<int> &nums,int i,long long a,long long b,long long c,long long d,const long long &target)
    {
        if (i==nums.size())
        {
            if (a==b && b==c && c==d && d==target)
                return true;
            else
                return false;
        }
        if (a>target || b>target || c>target || d>target)
            return false;
        return dfs(nums,i+1,a+nums.at(i),b,c,d,target)
        || dfs(nums,i+1,a,b+nums.at(i),c,d,target)
        || dfs(nums,i+1,a,b,c+nums.at(i),d,target)
        || dfs(nums,i+1,a,b,c,d+nums.at(i),target);
    }
};
