/*
 * 其实就是0 +- 1 +- 2 +- 3 +- 4 ··· +- ans ==target
   其target>0 还是<0都无所谓，因为是镜像的，可以通过改变+-号得到
   这里统一认定是target>0
 * 设0 +- 1 +- 2 +- 3 +- 4 ··· +- k >=target
 * 1. 若==target则直接返回
   2. 若>target，则设diff=sum-target，
      找到在sum中子集和为diff/2的部分，改变对应的符号即可，但是总步数没有改变，只改变了方向
   3. 但是如果diff不是偶数，即diff/2不是个整数，那么需要继续向右走，k+1、k+2、等等
      直到diff为偶数再返回策略2，实际上最多也只会走到k+2
 */
class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
        int step=1;
        int ans=0;
        int cur=0;
        while (cur<target)
        {
            ++ans;
            cur+=step;
            ++step;
        }
        int diff=cur-target;
        while (diff%2!=0)
        {
            ++ans;
            cur+=step;
            diff=cur-target;
            ++step;
        }
        return ans;
    }
};
