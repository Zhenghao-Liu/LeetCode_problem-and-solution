/**
* [已知两点，半径，求圆心坐标](https://www.zhihu.com/question/363995472/answer/958473071)
* 对每两个点进行求圆心，因为答案的圆在圆边上至少包含两个点（除了所有点都是相离情况）
* 然后对所有圆心求包括了多少个点求最大值即可
*/
class Solution {
    double diff=1e-8;
public:
    int numPoints(vector<vector<int>>& points, int r) {
        //倘若所有以points为圆心的圆都相离，那至少也要包含该点
        int ans=1;
        int points_size=points.size();
        for (int i=0;i<points_size;++i)
            for (int j=i+1;j<points_size;++j)
            {
                double a=points.at(i).at(0),b=points.at(i).at(1);
                double c=points.at(j).at(0),d=points.at(j).at(1);
                //判断是否相离
                if ((c-a)*(c-a)+(d-b)*(d-b)>2*r*2*r)
                    continue;
                double up=sqrt(double(4*r*r-((a-c)*(a-c)+(b-d)*(b-d))));
                double down=2.0*sqrt(double((a-c)*(a-c)+(b-d)*(b-d)));
                double x1=(a+c)/2.0+(b-d)*up/down;
                double y1=(b+d)/2.0+(c-a)*up/down;
                ans=max(ans,helper(x1,y1,points,r));
                double x2=(a+c)/2.0+(d-b)*up/down;
                double y2=(b+d)/2.0+(a-c)*up/down;
                if (x2!=x1 || y2!=y1)
                    ans=max(ans,helper(x2,y2,points,r));
            }
        return ans;
    }
    int helper(double x,double y,vector<vector<int>>& points,int r)
    {
        int count=0;
        for (vector<int> &i:points)
            if ( (x-i[0])*(x-i[0])+(y-i[1])*(y-i[1])<=r*r+diff )
                ++count;
        return count;
    }
};
