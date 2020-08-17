/*
* 首先对于pair中的[a,b][c,d]，a只关心d<c的情况，即只关心小的前元素
  所以按照[i][1]的升序排序
* dp[i]表示当前处理到i个序列时候，最长数对链有多长，且这个数对链一定是以pairs[i]结尾的
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)==B.at(1) ? A.at(0)<B.at(0) : A.at(1)<B.at(1);
        });
        int pairs_size=pairs.size();
        vector<int> dp(pairs_size,1);
        for (int i=1;i<pairs_size;++i)
        {
            for (int j=0;j<i;++j)
                if (pairs.at(j).at(1)<pairs.at(i).at(0))
                    dp.at(i)=max(dp.at(i),dp.at(j)+1);
                else
                    break;
        }
        int ans=1;
        for (int i:dp)
            ans=max(ans,i);
        return ans;
    }
};
