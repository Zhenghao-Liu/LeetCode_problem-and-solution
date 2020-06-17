//(A[i]+i)+(A[j]-j)以j为处理单元，贪心找i满足最大的A[i]+i
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int left=A.at(0);
        int A_size=A.size();
        int ans=INT_MIN;
        for (int j=1;j<A_size;++j)
        {
            ans=max(ans,left+A.at(j)-j);
            left=max(left,A.at(j)+j);
        }
        return ans;
    }
};
