// 最后一定是一个尖的中间大两边小的序列，从全1开始模拟递增
class Solution {
public:
    int maxValue(int n, int idx, int maxSum) {
        int can=maxSum-n;
        int l=idx,r=idx;
        int ans=1;
        while (can>0) {
            int need=r-l+1;
            if (can-need>=0) {
                if (l==0 && r==n-1) {
                    ans+=can/need;
                    break;
                }
                can-=need;
                ans++;
            } else {
                break;
            }
            l=max(l-1,0);
            r=min(r+1,n-1);
        }
        return ans;
    }
};