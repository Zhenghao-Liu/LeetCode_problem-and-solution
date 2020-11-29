/*
 * O(n2)
 * l2r[i]表示不包括i，左边要求升序序列(可以为空)的最少删除个数
   r2l[i]表示不包括i，右边要求升序序列(可以为空)的最少删除个数
 * 注意题目说明，山顶两侧都至少要有一个元素
 */
const int MAXN=1000;
int l2r[MAXN];
int r2l[MAXN];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int size=nums.size();
        memset(l2r,0x3f,sizeof(l2r));
        memset(r2l,0x3f,sizeof(r2l));
        for (int i=0;i<size;++i)
        {
            int t=i;
            for (int j=0;j<i;++j)
                if (nums.at(i)>nums.at(j))
                    t=min(t,l2r[j]+i-j-1);
            l2r[i]=t;
        }
        for (int i=size-1;i>=0;--i)
        {
            int t=size-i-1;
            for (int j=size-1;j>i;--j)
                if (nums.at(i)>nums.at(j))
                    t=min(t,r2l[j]+j-i-1);
            r2l[i]=t;
        }
        int ans=INF;
        for (int i=1;i<size-1;++i)
        {
            int l=l2r[i];
            int r=r2l[i];
            if (l!=i && r!=size-i-1)
                ans=min(ans,l+r);
        }
        return ans;
    }
};
