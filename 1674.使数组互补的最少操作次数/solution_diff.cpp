/*
 * 差分数组：
   * [i~j]区间加上inc
   * 则差分数组diff[i]+=inc diff[j+1]-=inc
   * 求原数组元素[i]，则是diff[0]+···+diff[i]
 * 枚举一对nums[i]和nums[n-1-i]可变成的所有可能的步数
 * 因为nums[i]<=limit，所以一对nums[i]和nums[n-1-i]和的范围是[2,2*limit]
   且差分数组要多开一位，加上索引问题，所以是2*MAXN+2
 * a=nums[i] b=nums[n-1-i]
   1. 0次操作：a+b
   2. 1次操作：只改一位数字，且去除a+b情况
   3. 2次操作：改两位数字，去除0次操作和1次操作情况
 */
const int MAXN=100000;
int diff[2*MAXN+2];
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        memset(diff,0,sizeof(diff));
        int size=nums.size();
        int group=size/2;
        int lo=2,hi=2*limit;
        for (int i=0;i<group;++i)
        {
            int a=nums.at(i),b=nums.at(size-1-i);
            int sum=a+b;
            diff[sum]+=-1; diff[sum+1]-=-1;
            int mi=min(min(a+1,a+limit),min(b+1,b+limit));
            int mx=max(max(a+1,a+limit),max(b+1,b+limit));
            diff[mi]+=1; diff[mx+1]-=1;
            if (mi>lo)
            {
                diff[lo]+=2; diff[mi]-=2;
            }
            if (mx<hi)
            {
                diff[mx+1]+=2; diff[hi+1]-=2;
            }
        }
        int ans=size;
        int sum=0;
        for (int i=2;i<=2*limit;++i)
        {
            sum+=diff[i];
            ans=min(ans,sum);
        }
        return ans;
    }
};
