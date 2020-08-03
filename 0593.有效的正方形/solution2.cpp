//如果是正方形，那么任意挑选3个点，一定是一个等腰直角三角形
class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        return is_triangle(p1,p2,p3) && is_triangle(p1,p2,p4) && is_triangle(p1,p3,p4) && is_triangle(p2,p3,p4);
    }
    bool is_triangle(vector<int> &a,vector<int> &b,vector<int> &c)
    {
        int d1=dis(a,b);
        int d2=dis(a,c);
        int d3=dis(b,c);
        if (d1==d2 && d3>d1 && d1+d2==d3)
            return true;
        if (d1==d3 && d2>d1 && d1+d3==d2)
            return true;
        if (d2==d3 && d1>d2 && d2+d3==d1)
            return true;
        return false;
    }
    int dis(vector<int> &a,vector<int> &b)
    {
        int x=a.at(0)-b.at(0);
        int y=a.at(1)-b.at(1);
        return x*x+y*y;
    }
};
