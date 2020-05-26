class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int ans=0;
        int A_size=A.size();
        //弱等差数列：至少有两个元素的，且任意两个相邻元素之差相同
        //dp[i][d]表示以A[i]结束且对应公差为d的弱等差数列个数
        //动态转移方程对于j<i，dp[i][ A[i]-A[j] ] += dp[j][ A[i]-A[j] ]+1
        //dp[j][  A[i]-A[j] ]才是真正的题目要求的等差数列
        vector<unordered_map<long long,int>> dp(A_size);
        for (int i=1;i<A_size;++i)
            for (int j=0;j<i;++j)
            {
                int count=0;
                long long d=(long long)A.at(i)-(long long)A.at(j);
                if (dp.at(j).find(d)!=dp.at(j).end())
                    count=dp.at(j).at(d);
                dp.at(i)[d]+=count+1;
                ans+=count;
            }
        return ans;
    }
};
