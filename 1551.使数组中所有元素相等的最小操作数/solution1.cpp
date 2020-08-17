//贪心的两端+1、-1，那步数一样，模拟半边即可
class Solution {
public:
    int minOperations(int n) {
        int target=n;
        int ans=0;
        for (int i=0;i<n/2;++i)
        {
            ans+=target-(2*i+1);
        }
        return ans;
    }
};
