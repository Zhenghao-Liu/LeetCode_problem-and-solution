/*
 * 状压
 * 先枚举出只有一个分组的所有情况
 * 再从0枚举到ALL
   因为从0枚举到i的过程，一定会把i的所有子集给先处理一遍，所以只用扫一趟就行了
   且二进制下从0枚举到ALL，再在i中枚举i的子集，这个复杂度是3^n
 */
const int MAXN=16;
int dp[1<<MAXN];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int size=nums.size();
        int each_size=size/k;
        int ALL=(1<<size)-1;
        memset(dp,0x3f,sizeof(dp)); 
        dp[0]=0;
        vector<int> show(size+1);
        for (int i:nums)
        {
            ++show.at(i);
            if (show.at(i)>k)
                return -1;
        }
        for (int j=0;j<=ALL;++j)
        {
            if ( __builtin_popcount(j)!=each_size)
                continue;
            int tmp=j;
            fill(show.begin(),show.end(),0);
            int idx=0;
            bool flag=true;
            int mx=INT_MIN,mi=INT_MAX;
            while (tmp>0)
            {
                if ((tmp&1)!=0)
                {
                    mx=max(mx,nums.at(idx));
                    mi=min(mi,nums.at(idx));
                    if (show.at(nums.at(idx))==1)
                    {
                        flag=false;
                        break;
                    }
                    show.at(nums.at(idx))=1;
                }
                ++idx;
                tmp>>=1;
            }
            if (!flag)
                continue;
            dp[j]=mx-mi;
        }
        for (int j=1;j<=ALL;++j)
        {
            if (__builtin_popcount(j)%each_size!=0)
                continue;
            int subset=j;
            do
            {
                int left=subset ^ j;
                if (dp[left]!=INF && dp[subset]!=INF)
                    dp[j]=min(dp[j],dp[left]+dp[subset]);
                subset=(subset-1)&j;
            }while(subset!=j);
        }
        return dp[ALL]==INF ? -1 : dp[ALL];
    }
};
