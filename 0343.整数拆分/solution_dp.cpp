class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp.at(1)=1;
        dp.at(2)=1;
        for (int i=3;i<=n;++i)
            for (int j=1;j<i;++j)
                dp.at(i)=max(dp.at(i),max(dp.at(j)*(i-j),j*(i-j)));
        return dp.at(n);
    }
};
