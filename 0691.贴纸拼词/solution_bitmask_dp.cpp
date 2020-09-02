/*
* 状压dp，数据量target长度<15
* 设0表示没有匹配该字符，1表示匹配了该字符
* 从全0状态转移到全1状态
*/
const int INF=0x3f3f3f3f;
const int MAXSS=50;
int stikers_count[MAXSS][26];
const int MAXTS=1<<15;
int dp[MAXTS];
class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        memset(stikers_count,0,sizeof(stikers_count));
        int stickers_size=stickers.size();
        //统计stickers中每个单词中字母出现次数
        for (int i=0;i<stickers_size;++i)
            for (char j:stickers.at(i))
                ++stikers_count[i][j-'a'];
        int target_size=target.size();
        memset(dp,0x3f,sizeof(dp));
        //全集
        int ALL=(1<<target_size)-1;
        //空字符只需要0个贴纸
        dp[0]=0;
        //遍历所有情况
        for (int i=0;i<=ALL;++i)
        {
            if (dp[i]==INF)
                continue;
            for (int j=0;j<stickers_size;++j)
            {
                int nxt=i;
                int count[26];
                copy(stikers_count[j],stikers_count[j]+26,count);
                for (int k=0;k<target_size;++k)
                {
                    if ((i&(1<<k))!=0)
                        continue;
                    if (count[target.at(k)-'a']>0)
                    {
                        nxt|=1<<k;
                        --count[target.at(k)-'a'];
                    }
                }
                dp[nxt]=min(dp[nxt],dp[i]+1);
            }
        }
        return dp[ALL]==INF ? -1 : dp[ALL];
    }
};
