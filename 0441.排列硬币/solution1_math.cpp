class Solution {
public:
    int arrangeCoins(int n) {
        long long ans=1;
        long long res=1;
        while (res<=n)
        {
            ++ans;
            res=(ans+ans*ans)/2;
        }
        return ans-1; 
    }
};
