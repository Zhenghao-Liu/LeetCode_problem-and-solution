//按行遍历，判断该行与上一行是否是错位1个之后相等
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size(),column=matrix.at(0).size();
        for (int i=1;i<row;++i)
        {
            bool flag=true;
            for (int j=1;j<column;++j)
                if (matrix.at(i).at(j)!=matrix.at(i-1).at(j-1))
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
