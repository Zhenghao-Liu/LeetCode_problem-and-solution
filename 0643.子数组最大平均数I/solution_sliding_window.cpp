class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        int ans=-3e8;
        int nums_size=nums.size();
        for (int i=0;i<k-1;++i)
            sum+=nums.at(i);
        for (int i=k-1;i<nums_size;++i)
        {
            if (i!=k-1)
                sum-=nums.at(i-k);
            sum+=nums.at(i);
            ans=max(ans,sum);
        }
        return 1.0*ans/k;
    }
};
