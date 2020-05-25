class Solution {
public:
    int arrangeCoins(int n) {
        long long sum=0;
        int ans=1;
        while (sum+ans<=n)
        {
            sum+=ans;
            ++ans;
        }
        return ans-1; 
    }
};
