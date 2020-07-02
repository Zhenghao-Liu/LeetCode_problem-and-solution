/*
* 模拟行走路径
* 向上：上一次终点不在最后一行，则起点在前一个终点的下方，否则在右方
* 向下：上一次终点不在最后一列，则起点在前一个终点的右方，否则在下方
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return {};
        int row=matrix.size(),column=matrix.at(0).size();
        vector<int> ans;
        ans.reserve(row*column);
        bool judge_up=true;
        int x=-1,y=0;
        while (ans.size()<row*column)
        {
            if (judge_up)
            {
                if (x!=row-1)
                    ++x;
                else
                    ++y;
                while(x>=0 && y<column)
                {
                    ans.push_back(matrix.at(x).at(y));
                    --x;
                    ++y;
                }
                ++x;
                --y;
            }
            else
            {
                if (y!=column-1)
                    ++y;
                else
                    ++x;
                while (x<row && y>=0)
                {
                    ans.push_back(matrix.at(x).at(y));
                    ++x;
                    --y;
                }
                --x;
                ++y;
            }
            judge_up=!judge_up;
        }
        return ans;
    }
};
