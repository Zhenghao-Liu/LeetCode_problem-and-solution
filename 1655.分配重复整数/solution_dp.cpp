/*
 * 先构造出出现次数的cnt数组
 * 因为1<=m<=10，所以拿m来状压
 * dp[i][j]表示 cnt前i个元素(以0开头) 满足 二进制下顾客为j 的情况
 * 当前处理的是第i个cnt元素，顾客状态是j，设j的一个子集是s，s的补集写成j-s
   可以考虑让cnt[i]满足状态j的一个子集s，即cnt[i]>=状态j下的要求
   那么就需要让cnt[0~i-1]满足顾客剩下的状态即s的补集即j-s
   当然前提是dp[i-1][j-s]是已经满足的即为true
 * 初始化dp[i][空集]=true，没有顾客要求自然一定能满足
 * 结果是dp[cnt_size-1][二进制下全1的状态]
 * 优化
   1. 如果dp[i-1][j]已经为true了，那么dp[i][j]自然也是true，剪枝
   2. 可以先预处理求出所有可能的状态j下客户的总要求是多少
 */
const int MAXV=1001;
int show_t[MAXV];
const int MAXN=50;
int cnt[MAXN];
const int MAXM=10;
int sum[1<<MAXM];
bool dp[MAXN][1<<MAXM];
class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        memset(show_t,0,sizeof(show_t));
        for (int i:nums)
            ++show_t[i];
        memset(cnt,0,sizeof(cnt));
        int cnt_size=0;
        for (int i=1;i<MAXV;++i)
            if (show_t[i]!=0)
            {
                cnt[cnt_size]=show_t[i];
                ++cnt_size;
            }
        int quantity_size=quantity.size();
        int ALL=(1<<quantity_size)-1;
        memset(sum,0,sizeof(sum));
        for (int i=1;i<=ALL;++i)
        {
            int cur=i;
            int idx=0;
            while (cur!=0)
            {
                if ((cur&1)!=0)
                    sum[i]+=quantity.at(idx);
                cur>>=1;
                ++idx;
            }
        }
        memset(dp,false,sizeof(dp));
        for (int i=0;i<cnt_size;++i)
            dp[i][0]=true;
        for (int j=1;j<=ALL;++j)
            if (cnt[0]>=sum[j])
                dp[0][j]=true;
        for (int i=1;i<cnt_size;++i)
            for (int j=1;j<=ALL;++j)
            {
                if (dp[i-1][j])
                {
                    dp[i][j]=true;
                    continue;
                }
                int subset=j;
                do
                {
                    if (subset==0)
                        break;
                    int complements=(~subset)&j;
                    if (dp[i-1][complements] && cnt[i]>=sum[subset])
                    {
                        dp[i][j]=true;
                        break;
                    }
                    subset=(subset-1)&j;
                }while(subset!=j);
            }
        return dp[cnt_size-1][ALL];
    }
};
