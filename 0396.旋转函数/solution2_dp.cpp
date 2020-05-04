class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int A_size=A.size();
        if (A_size==0)
            return 0;
        long long sum=0;
        int dp=0;
        for (int i=0;i<A_size;++i)
        {
            dp+=i*A.at(i);
            sum+=A.at(i);
        }
        int ans=dp;
        for (int i=1;i<A_size;++i)
        {
            dp+=(sum-(long long)A_size*A.at(A_size-i));
            if (dp>ans)
                ans=dp;
        }
        return ans;
    }
};
