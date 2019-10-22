/*
* 直接合成一个区间
* 然后按照上一题的方法先排序后操作
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(vector<int>(newInterval));
        sort(intervals.begin(),intervals.end(),cmp);
        int index=0;
        vector<vector<int>> answer;
        answer.push_back(vector<int>(intervals.at(0)));
        int intervals_size=intervals.size();
        for (int i=1;i<intervals_size;++i)
        {
            if (answer.at(index).at(1)>=intervals.at(i).at(0))
                answer.at(index).at(1)=max(answer.at(index).at(1),intervals.at(i).at(1));
            else
            {
                answer.push_back(vector<int>(intervals.at(i)));
                ++index;
            }
        }
        return answer;
    }
    static bool cmp(const vector<int> &A,const vector<int> &B)
    {
        if (A.at(0)==B.at(0))
            return A.at(1)<B.at(1);
        return A.at(0)<B.at(0);
    }
};
