//贪心：左端点确定情况下，右端点越远越好
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(),clips.end());
        int start=0;
        int size=clips.size();
        int ans=0;
        int i=0;
        while (start<T && i<size)
        {
            int mx=start;
            while (i<size && clips.at(i).at(0)<=start)
            {
                mx=max(mx,clips.at(i).at(1));
                ++i;
            }
            if (mx!=start)
            {
                ++ans;
                start=mx;
            }
            else
                return -1;
        }
        return start>=T ? ans : -1;
    }
};
