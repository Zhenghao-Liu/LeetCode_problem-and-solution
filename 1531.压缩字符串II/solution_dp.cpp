/*
* dp[i][len][k]表示处理到第i个字符即S[1~i]（设s下标以1开始），里面删除k个字符，且保证最后一个即s[i-1]没有被删除，最后一个字符即s[i-1]最后连续了len长，的最短压缩编码长度
* 那么转移自然是从j(j<i)转移到i
  dp[j][_len][_k]转移到dp[i][len][k]
  即中间要删除[j+1 ··· i-1]字符，即要删除i-1-(j+1)+1=i-1-j个字符
  1. 若s[i-1]!=s[j-1]，则代表s[j-1]不会连续，那么s[i-1]的连续长度为1即len必定为1，且多删除了i-1-j个字符，压缩编码长度因为多了s[i-1]所以是原来基础上加1即多加了单个字母
     dp[i][1][k+(i-1-j)]=dp[j][len][k]+1
  2. 若s[i-1]==s[j-1]，则代表删除后s[i-1]与会s[j-1]会连续，但别忘了s[j-1]可能已经有自带的连续了
     dp[i][len+1][k+(i-1-j)]=dp[j][len][k]+差值
     差值=先减去s[j-1]自身自带的连续的值，再加上len+1的价值
* 但是这样dp有一个问题，dp确保最后最后一个字母不被删除，所以在原有s上增加一个冗余字母，最后ans-1就是不包括冗余字母的压缩字符编码最小长度
  因为是冗余字母，即len必然为1，且题目是最多删除k个字符，显然删除的越多最后压缩编码长度越小，即最后return dp[size(这个size是包括了冗余的)][1][k]-1;
*/
const int MAXN=100+10;
int dp[MAXN][MAXN][MAXN];
class Solution {
public:
    int getLengthOfOptimalCompression(string s, int k) { 
        memset(dp,0x3f,sizeof(dp));
        s+='@';
        dp[0][0][0]=0;
        int size=s.size();
        for (int i=1;i<=size;++i)
        {
            char cur=s.at(i-1);
            for (int j=0;j<i;++j)
            {
                char prev;
                if (j==0)
                    prev='#';
                else
                    prev=s.at(j-1);
                for (int len=0;len<=j;++len)
                    for (int delete_k=0;delete_k<=j && delete_k+(i-1-j)<=k;++delete_k)
                    {
                        if (dp[j][len][delete_k]==0x3f3f3f3f)
                            continue;
                        if (cur!=prev)
                            dp[i][1][delete_k+(i-1-j)]=min(dp[i][1][delete_k+(i-1-j)],dp[j][len][delete_k]+1);
                        else
                            dp[i][len+1][delete_k+(i-1-j)]=min(dp[i][len+1][delete_k+(i-1-j)],dp[j][len][delete_k]-count(len)+count(len+1));
                    }
            }    
        }
        return dp[size][1][k]-1;
    }
    int count(int num)
    {
        if (num==1)
            return 0;
        if (num<10)
            return 1;
        if (num<100)
            return 2;
        if (num==100)
            return 3;
        return -1;
    }
};
