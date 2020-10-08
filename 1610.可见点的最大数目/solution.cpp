/*
 * 先用atan2装换成弧度，之后转换成角度制
 * 之后类似于滑窗的范围去扫描angle的扇形区域内最多可以观察有多少个节点
 * 但是有个问题是:第二象限和第三象限的问题，因为是按照角度升序排，即是顺时针的方向，
   但是无法扫描到第二象限90~180到第三象限-180~-90
   eg:-135、135,其实夹角只有90度
   所以复制一轮角度且全部加上360度加上原有数组后面
   即eg:-135、135、225、495
 */
const double eps=1e-5;
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int x=location.at(0);
        int y=location.at(1);
        int size=points.size();
        vector<double> vec;
        int same=0;
        for (int i=0;i<size;++i)
        {
            int a=points.at(i).at(0);
            int b=points.at(i).at(1);
            if (x==a && y==b)
            {
                ++same;
                continue;
            }
            double ang=atan2((b-y),(a-x))*180.0/M_PI;
            vec.push_back(ang);
        }
        sort(vec.begin(),vec.end());    
        int ans=0;
        int j=0;
        int siz=vec.size();
        for (int i=0;i<siz;++i)
            vec.push_back(vec.at(i)+360);
        for (int i=0;i<vec.size();++i)
            while (j<vec.size() && vec.at(j)-vec.at(i)<=(double)angle+eps)
            {
                ++j;
                ans=max(ans,j-i);
            }
        return ans+same;
    }
};
