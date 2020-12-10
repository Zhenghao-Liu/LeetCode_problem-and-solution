/*
 * 翻转行和列的顺序不影响最终结果
 * 因为是翻转总分，所以越高位是1越好，所以先贪心的让第一列变成全1,即行翻转
 * 之后再统计每一列是0多还是1多，尽可能的多变成1，即列翻转
 */
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int row=A.size();
        int col=A.at(0).size();
        int ans=0;
        ans+=row*(1<<(col-1));
        int one=0;
        for (int j=1;j<col;++j)
        {
            one=0;
            for (int i=0;i<row;++i)
                if (A.at(i).at(0)==1)
                    one+=A.at(i).at(j);
                else
                    one+= 1 ^ A.at(i).at(j);
            int cho=max(one,row-one);
            ans+=cho*(1<<(col-j-1));
        }
        return ans;
    }
};
