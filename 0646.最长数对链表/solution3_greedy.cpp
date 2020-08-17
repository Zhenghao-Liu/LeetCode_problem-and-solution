//先排序，后贪心，问题就变成了435.无重叠区间，即一个末尾越小越好，即末尾越小越能保证下一个的开头有更大选择范围
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)==B.at(1) ? A.at(0)<B.at(0) : A.at(1)<B.at(1);
        });
        int pairs_size=pairs.size();
        int ans=1;
        int prev=pairs.at(0).at(1);
        for (int i=1;i<pairs_size;++i)
        {
            if (pairs.at(i).at(0)>prev)
            {
                prev=pairs.at(i).at(1);
                ++ans;
            }
        }
        return ans;
    }
};
