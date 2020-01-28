class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp.at(0)=1;
        int p_2,p_3,p_5;
        p_2=p_3=p_5=0;
        for (int i=1;i<n;++i)
        {
            dp.at(i)=min(min(2*dp.at(p_2),3*dp.at(p_3)),5*dp.at(p_5));
            if (dp.at(i)==2*dp.at(p_2))
                ++p_2;
            if (dp.at(i)==3*dp.at(p_3))
                ++p_3;
            if (dp.at(i)==5*dp.at(p_5))
                ++p_5;
        }
        return dp.at(n-1);
    }
};
