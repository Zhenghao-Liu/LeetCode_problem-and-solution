/**
* 先按照起点排序
* 对于一个气球设为基准1，该气球2是基准的下一个气球
* 若该气球的起点 小于等于 基准的终点，那么说明可以1箭两球
* 倘若该气球起点 大于 基准的终点，则要2箭
* 那对于下一个气球3呢，他是气球2的下一个气球
* 这时候要比较的就不是气球1的终点了，因为有可能气球2的终点小于气球1的终点
  所以要通过设置一个末端的标志end，来表明要想不多箭的情况的末端是哪个

* 每一次都要比较末尾的最小值比较麻烦，不如直接按照末尾的升序来排
* 要多一只箭的情况即：该气球的起点 大于 end，且多一只箭后要更新end
* 否则不多箭且按末尾的升序来排，那么end一定是当前箭所击破气球终点的最小值
*/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int points_size=points.size();
        if (points_size<=1)
            return points_size;
        sort(points.begin(),points.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)<B.at(1);
        });
        //有气球那么最少都需要1箭
        int ans=1;
        int end=points.at(0).at(1);
        for (int i=1;i<points_size;++i)
        {
            if (points.at(i).at(0)>end)
            {
                ++ans;
                end=points.at(i).at(1);
            }
        }
        return ans;
    }
};
