//计算出可能范围点的上下左右边界，然后去暴力枚举
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int r) {
        int left,right,up,down;
        left=down=INT_MAX;
        right=up=INT_MIN;
        for (vector<int> &i:towers)
        {
            int x=i.at(0),y=i.at(1);
            left=min(left,x-r);
            right=max(right,x+r);
            up=max(up,y+r);
            down=min(down,y-r);
        }
        int ansa=INT_MAX,ansb=INT_MAX;
        int ansv=0;
        for (int i=left;i<=right;++i)
            for (int j=down;j<=up;++j)
            {
                int v=0;
                for (vector<int> &z:towers)
                {
                    int x=z.at(0),y=z.at(1),q=z.at(2);
                    double dis=get_dis(x,y,i,j);
                    dis=sqrt(dis);
                    if (dis<=r)
                        v+=q/(1+dis);
                }
                if (v>ansv)
                {
                    ansa=i;
                    ansb=j;
                    ansv=v;
                }
            }
        return {ansa,ansb};
    }
    double get_dis(double x,double y,double a,double b)
    {
        return (a-x)*(a-x)+(b-y)*(b-y);
    }
};
