class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ans=-1;
        int mx=INT_MAX;
        int sz=points.size();
        for (int i=0;i<sz;i++) {
            int a=points.at(i).at(0),b=points.at(i).at(1);
            if (a==x || b==y) {
                int dis=abs(a-x)+abs(b-y);
                if (dis<mx) {
                    mx=dis;
                    ans=i;
                }
            }
        }
        return ans;
    }
};
