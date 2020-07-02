/*
* 一条斜线上的matrix[i][j]中的i+j是一个常数，通过常数大小划分斜线遍历顺序
* 并通奇偶判断是向上还是向下
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int row=matrix.size(),column=matrix.at(0).size();
        vector<pair<int,int>> pos;
        pos.reserve(row*column);
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                pos.push_back({i,j});
        sort(pos.begin(),pos.end(),[](const pair<int,int>& A,const pair<int,int>& B)->bool{
            int A_sum=A.first+A.second;
            int B_sum=B.first+B.second;
            if (A_sum!=B_sum)
                return A_sum<B_sum;
            if (A_sum%2==0)
                return A.first>B.first;
            else
                return A.first<B.first;
        });
        vector<int> ans;
        ans.reserve(row*column);
        for (pair<int,int> &i:pos)
            ans.push_back(matrix.at(i.first).at(i.second));
        return ans;
    }
};
