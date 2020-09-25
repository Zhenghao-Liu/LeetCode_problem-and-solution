//为了大值的dp能借助小值的dp，先进行排序
struct point
{
    int x;
    int y;
    int val;
};
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if (row==0)
            return 0;
        int column=matrix.at(0).size();
        vector<point> helper;
        helper.reserve(row*column);
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                helper.push_back(point{i,j,matrix.at(i).at(j)});
        sort(helper.begin(),helper.end(),[](const point &A,const point &B){return A.val<B.val;});
        vector<vector<int>> dp(row,vector<int>(column,1));
        int ans=1;
        for (point &i:helper)
        {
            int x=i.x;
            int y=i.y;
            int val=i.val;
            //左
            if (y>0 && val>matrix.at(x).at(y-1) && dp.at(x).at(y-1)+1>dp.at(x).at(y))
                dp.at(x).at(y)=dp.at(x).at(y-1)+1;
            //上
            if (x>0 && val>matrix.at(x-1).at(y) && dp.at(x-1).at(y)+1>dp.at(x).at(y))
                dp.at(x).at(y)=dp.at(x-1).at(y)+1;
            //右
            if (y+1<column && val>matrix.at(x).at(y+1) && dp.at(x).at(y+1)+1>dp.at(x).at(y))
                dp.at(x).at(y)=dp.at(x).at(y+1)+1;
            //下
            if (x+1<row && val>matrix.at(x+1).at(y) && dp.at(x+1).at(y)+1>dp.at(x).at(y))
                dp.at(x).at(y)=dp.at(x+1).at(y)+1;
            if (dp.at(x).at(y)>ans)
                ans=dp.at(x).at(y);
        }
        return ans;
    }
};
