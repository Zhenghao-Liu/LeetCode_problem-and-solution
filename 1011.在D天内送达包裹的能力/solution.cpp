class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l=*max_element(weights.begin(),weights.end()),r=accumulate(weights.begin(),weights.end(),0);
        while (l<r) {
            int mid=l+(r-l)/2;
            int cur=0,cnt=1;
            for (int i:weights) {
                if (cur+i>mid) {
                    cnt++;
                    cur=i;
                } else {
                    cur+=i;
                }
            }
            if (cnt<=D) {
                r=mid;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
};