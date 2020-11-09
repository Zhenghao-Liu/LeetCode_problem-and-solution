class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int r=-1;
        int sum=0;
        int ans=INT_MAX;
        int size=nums.size();
        for (int i=0;i<size;++i)
        {
            if (i!=0)
                sum-=nums.at(i-1);
            if (r+1<size && sum<s)
                do
                {
                    ++r;
                    sum+=nums.at(r);
                }while (r+1<size && sum<s);
            if (sum>=s)
                ans=min(ans,r-i+1);
        }
        return ans==INT_MAX ? 0 : ans;
    }
};
