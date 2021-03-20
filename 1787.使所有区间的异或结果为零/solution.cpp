/*
 * a1 ^ a2 ^ ··· ak==0
   a2 ^ a3 ^ ··· ak+1==0
 * 即 a1==ak+1==a2k+1==···
      a2==ak+2==a2k+2==···
      以此类推
 * 所以我们只需要讨论前k个位置变成什么，就可以决定最后整个数组变化完之后是怎样的
 * dp[i][j]表示当前考虑到nums[i]这个位置，从nums[0]^nums[1]^···nums[i]==j的最少变换次数
 * 因为只用讨论前k个位置，但是还是要顾及到后面对应的k分组的位置
   所以用一个group.at(i).at(j)表示位置i（映射到k个一组的位置）值为j的个数
   以及cnt.at(i)表示位置i（映射到k个一组的位置）一共有多少个数字
 * 初始化：dp[0][j]则是看有多少个数字不是j即可  
 * 转移
   1. 将位置i（映射到k个一组的位置）的所有值都改成一个数字，使得总异或结果是j，
      但是改成什么数字我不关心，我只需要选择dp[i-1][所有j]的最小值，
      加上当前位置i（映射到k个一组的位置）一共有多少个数字即cnt.at(i)即可
   2. 保留一种已经在这个位置有出现的数字，把该位置其他剩下的数字变成这个保留的数字
      先去枚举上一个位置的所有结果j可能，
      再去枚举位置i（映射到k个一组的位置）有哪些元素，即去枚举[cur,times]:group.at(i)，
      他们的异或结果就是nxt=j^cur，异或后的步数即是dp[i][nxt]=dp[i-1]+cnt.at(i)-times
 * 最终的答案就是dp[k-1][0]     
 */
const int MAXK=2e3;
const int MAXI=1<<10;
int dp[MAXK][MAXI];
const int INF=0x3f3f3f3f;
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int sz=nums.size();
        vector<unordered_map<int,int>> group(k);
        vector<int> cnt(k);
        for (int i=0;i<k;i++) {
            for (int j=i;j<sz;j+=k) {
                group.at(i)[nums.at(j)]++;
                cnt.at(i)++;
            }
        }
        memset(dp,0x3f,sizeof(int)*k*MAXI);
        for (int j=0;j<MAXI;j++) {
            auto p=group.at(0).find(j);
            if (p==group.at(0).end()) {
                dp[0][j]=cnt.at(0);
            } else {
                dp[0][j]=cnt.at(0)-(p->second);
            }
        }
        for (int i=1;i<k;i++) {
            int mi=INF;
            for (int j=0;j<MAXI;j++) {
                mi=min(mi,dp[i-1][j]);
            }
            for (int j=0;j<MAXI;j++) {
                dp[i][j]=min(dp[i][j],mi+cnt.at(i));
            }
            for (int j=0;j<MAXI;j++) {
                for (auto &[cur,times]:group.at(i)) {
                    int nxt=j^cur;
                    dp[i][nxt]=min(dp[i][nxt],dp[i-1][j]+cnt.at(i)-times);
                }
            }
        }
        return dp[k-1][0];
    }
};
