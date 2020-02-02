//动态规划dp.at(i)=min(dp.at(i),dp.at(i-j*j)+1);
//可以把n分解成n=a+b，a是普通数字，b是一个完全平方数(1,4,9,16.....)
//比较所有可能的b情况，最小即最优
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1);
        dp.at(0)=0;
        for (int i=1;i<n+1;++i)
        {
            //最坏的情况就是i个1相加，即i
            dp.at(i)=i;
            //当i-j*j=0时则表明n为完全平方数，则结果必为1
            for (int j=1;i-j*j>=0;++j)
                if (dp.at(i-j*j)+1<dp.at(i))
                    dp.at(i)=dp.at(i-j*j)+1;
        }
        return dp.at(n);
    }
};
