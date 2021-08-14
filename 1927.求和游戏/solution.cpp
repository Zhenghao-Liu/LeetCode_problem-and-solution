// 可以把两边的和相等，看成是左边和减右边和，最后目标是让差为0
// alice会尽可能使差不为0，bob为尽可能使差为0
// 只有两种方向，要么让差一直变大，要么让差一直变小
// 枚举两种情况即可
class Solution {
public:
    bool sumGame(string num) {
        int sz=num.size();
        int ls=0,lc=0;
        for (int i=0;i<sz/2;i++) {
            if (num.at(i)=='?') {
                lc++;
            } else {
                ls+=num.at(i)-'0';
            }
        }
        int rs=0,rc=0;
        for (int i=sz/2;i<sz;i++) {
            if (num.at(i)=='?') {
                rc++;
            } else {
                rs+=num.at(i)-'0';
            }
        }
        {
            int l=lc,r=rc;
            int res=rs-ls;
            int all=lc+rc;
            int ali=(all+1)/2,bob=all-ali;
            int tak=min(ali,l);
            res-=tak*9;
            ali-=tak;
            r-=ali;
            if (!(r*9+res>=0)) {
                return true;
            }
        }
        {
            int l=lc,r=rc;
            int res=rs-ls;
            int all=lc+rc;
            int ali=(all+1)/2,bob=all-ali;
            int tak=min(ali,r);
            res+=tak*9;
            ali-=tak;
            l-=ali;
            if (!(l*(-9)+res<=0)) {
                return true;
            }
        }
        return false;
    }
};