//任意两个点之间的距离只有两种：正方形的边，或者是正方形的对角线；倘若出现不是这两条边，或者边距离为0即点重合情况都返回false
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> all{p1,p2,p3,p4};
        int a=INT_MAX;
        int b=INT_MAX;
        for (int i=0;i<4;++i)
        {
            for (int j=i+1;j<4;++j)
            {
                int d=dis(all.at(i),all.at(j));
                if (d==0)
                    return false;
                if (a==INT_MAX)
                    a=d;
                else if (d!=a && b==INT_MAX)
                    b=d;
                else if (d==a || d==b)
                    continue;
                else
                    return false;
            }
        }
        return true;
    }
    int dis(vector<int> &a,vector<int> &b)
    {
        int x=abs(a.at(0)-b.at(0));
        int y=abs(a.at(1)-b.at(1));
        return x*x+y*y;
    }
};
