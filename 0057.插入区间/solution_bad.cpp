/*
* 因为采用了vector.erase()导致时间巨慢
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
        if (position!=0)
            --position;
        while (position<intervals_size)
        {
            if (position<intervals_size-1 && intervals.at(position).at(1)>=intervals.at(position+1).at(0))
            {
                intervals.at(position).at(1)=max(intervals.at(position).at(1),intervals.at(position+1).at(1));
                intervals.erase(intervals.begin()+position+1);
                --intervals_size;
            }
            else
                ++position;
        }
        return intervals;
    }
};
