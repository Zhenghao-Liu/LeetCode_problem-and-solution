/*
 * 一定是x个'a'即1，加上一个'y'，加上z个'z'
 * 则方程组 x+y+z=n
           x+y+26z=k
 * 字典序最小，即x越大越好，且y<=1
   即 26*(y+z)>=k-x , 那么一直去试x，试到x的最大值
   单独讨论y，以及剩下的z
 */
class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans;
        int l=0;
        int r=n;
        while (r*26>=k-l)
        {
            ++l;
            --r;
        }
        --l;
        ++r;
        ans.append(l,'a');
        int idx=max(0,k-l-(r-1)*26);
        if (idx>0)
            ans+=char(idx-1+'a');
        if (r-1>0)
            ans.append(r-1,'z');
        return ans;
    }
};
