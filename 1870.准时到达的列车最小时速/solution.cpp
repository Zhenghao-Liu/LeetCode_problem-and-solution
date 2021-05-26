class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int sz=dist.size();
        if (sz-1>=hour) {
            return -1;
        }
        int l=1,r=max(*max_element(dist.begin(),dist.end()),(int)ceil(dist.back()/(hour-(sz-1))));
        while (l<r) {
            double mid=l+(r-l)/2;
            double cur=0;
            for (int i=0;i<sz-1;i++) {
                cur+=(int)ceil(dist.at(i)/mid);
            }
            cur+=dist.back()/mid;
            if (cur<=hour) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
};