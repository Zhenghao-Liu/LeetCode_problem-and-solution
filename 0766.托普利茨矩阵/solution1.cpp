//斜着遍历即i+1,j+1往下走
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size(),column=matrix.at(0).size();
        for (int i=row-1;i>=0;--i)
        {
            int cur=matrix.at(i).at(0);
            bool flag=true;
            for (int x=i+1,y=1;x<row && y<column;++x,++y)
                if (matrix.at(x).at(y)!=cur)
                {
                    flag=false;
                    break;
                }
            if (!flag)
                return false;
        }
        for (int j=1;j<column;++j)
        {
            int cur=matrix.at(0).at(j);
            bool flag=true;
            for (int x=1,y=j+1;x<row && y<column;++x,++y)
                if (matrix.at(x).at(y)!=cur)
                {
                    flag=false;
                    break;
                }
            if (!flag)
                return false;
        }
        return true;
    }
};
