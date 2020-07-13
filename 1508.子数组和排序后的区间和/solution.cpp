int base=1e9+7;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sum;
        sum.reserve((n+1)*n/2);
        for (int i=0;i<n;++i)
        {
            int a=0;
            for (int j=i;j<n;++j)
            {
                a+=nums.at(j);
                sum.push_back(a);
            }
        }
        sort(sum.begin(),sum.end());
        int ans=0;
        for (int i=left-1;i<right;++i)
        {
            ans+=sum.at(i);
            ans%=base;
        }
        return ans;
    }
};
