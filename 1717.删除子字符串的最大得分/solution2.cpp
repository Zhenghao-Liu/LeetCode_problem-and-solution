/*
 * ab -> x
 * ba -> y
 * 贪心的先去构建价值高的情况甲的，这样子剩下就只有可能情况乙
 */
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int a=0,b=0;
        s+='-';
        int ans=0;
        for (char i:s) {
            if (i=='a' || i=='b') {
                if (i=='a') {
                    a++;
                } else {
                    b++;
                }
                if (x>=y && i=='b' && a>0) {
                    a--;
                    b--;
                    ans+=x;
                } else if (x<=y && i=='a' && b>0) {
                    a--;
                    b--;
                    ans+=y;
                }
            } else {
                int cho=min(a,b);
                int val=min(x,y);
                ans+=cho*val;
                a=b=0;
            }
        }
        return ans;
    }
};
