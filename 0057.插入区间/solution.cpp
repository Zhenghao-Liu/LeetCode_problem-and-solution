/*
* 最优的方法
* 采用二分法寻找插入的位置
* 无判断输入位置前的区间
* 判断插入位置及后面有无交集
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int intervals_size=intervals.size();
        if (intervals_size==0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        int left=0,right=intervals_size-1,mid,position=-1;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (intervals.at(mid).at(0)==newInterval.at(0))
            {
                position=mid;
                break;
            } 
            else if (intervals.at(mid).at(0)<newInterval.at(0))
                left=mid+1;
            else
                right=mid-1;
        }
        if (position==-1)
        {
            intervals.insert(intervals.begin()+left,newInterval);
            position=left;
        }
        else
            intervals.insert(intervals.begin()+position,newInterval);
        ++intervals_size;
        vector<vector<int>> answer;
        if (position==0)
            position=1;
        for (int i=0;i<position;++i)
            answer.push_back(intervals.at(i));
        --position;
        for (int i=position+1;i<intervals_size;++i)
            if (answer.at(position).at(1)>=intervals.at(i).at(0))
                answer.at(position).at(1)=max(answer.at(position).at(1),intervals.at(i).at(1));
            else
            {
                answer.push_back(vector<int>(intervals.at(i)));
                ++position;
            }        
        return answer;
    }
};
