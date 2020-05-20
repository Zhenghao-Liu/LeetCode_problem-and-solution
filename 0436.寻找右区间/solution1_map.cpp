//key=[j][0] value=j，且要求最小，所以哈希表只用存[j][0]出现的最左边的情况 
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int intervals_size=intervals.size();
        map<int,int> helper;
        for (int i=0;i<intervals_size;++i)
            if (helper.find(intervals.at(i).at(0))==helper.end())
                helper[intervals.at(i).at(0)]=i;
        vector<int> ans(intervals_size,-1);
        for (int i=0;i<intervals_size;++i)
        {
            map<int,int>::iterator p=helper.lower_bound(intervals.at(i).at(1));
            if (p==helper.end())
                ans.at(i)=-1;
            else
                ans.at(i)=(*p).second;
        }
        return ans;
    }
};
