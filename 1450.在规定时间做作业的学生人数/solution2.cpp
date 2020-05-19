class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
       int ans=0;
       int size=startTime.size();
       for (int i=0;i<size;++i)
        if (queryTime>=startTime.at(i) && queryTime<=endTime.at(i))
            ++ans;
        return ans;
    }
};
