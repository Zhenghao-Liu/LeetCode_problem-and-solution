class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        multiset<long long> helper;
        helper.insert(0);
        int ans=0;
        long long sum=0;
        for (int &i:nums)
        {
            sum+=i;
            ans+=distance(helper.lower_bound(sum-upper),helper.upper_bound(sum-lower));
            helper.insert(sum);
        }
        return ans;
    }
};
