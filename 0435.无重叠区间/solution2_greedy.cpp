/**
* 转换成最大无重叠区间有多少个
* 按照[i][1]的升序排序
* 贪心，可以抽象理解为这些区间时一天中事情的时间表，能做最多多少件事，一件事结束的越早，那我越能开始下一个事
  即一个区间的[i][1]越小越好
*/
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int intervals_size=intervals.size();
        if (intervals_size==0)
            return 0;
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b){
            return a.at(1)==b.at(1) ? a.at(0)<b.at(0) : a.at(1)<b.at(1);
        });
        int pre=intervals.at(0).at(1);
        int max_nooverlap=1;
        for (int i=1;i<intervals_size;++i)
        {
            if (intervals.at(i).at(0)>=pre)
            {
                pre=intervals.at(i).at(1);
                ++max_nooverlap;
            }
        }
        return intervals_size-max_nooverlap;
    }
};
