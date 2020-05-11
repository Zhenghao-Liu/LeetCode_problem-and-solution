//dp[i]表示以A[i]为结尾的等差数列有多少个
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int A_size=A.size();
        vector<int> dp(A_size);
        int ans=0;
        for (int i=2;i<A_size;++i)
            if (A.at(i)-A.at(i-1)==A.at(i-1)-A.at(i-2))
            {
                dp.at(i)=dp.at(i-1)+1;
                ans+=dp.at(i);
            }
        return ans;
    }
};
