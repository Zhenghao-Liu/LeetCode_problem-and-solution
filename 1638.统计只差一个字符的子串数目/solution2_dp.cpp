/*
 * n^2的dp方法
 * same[i][j]表示以s[i]、t[j]结尾的相同子数组有多少个
 * diff[i][j]表示以s[i]、t[j]结尾的有一个字符不同的其他剩下字符都相同的子数组有多少个
 */
const int MAXN=100;
int same[MAXN][MAXN];
int diff[MAXN][MAXN];
class Solution {
public:
    int countSubstrings(string s, string t) {
        int s_size=s.size();
        int t_size=t.size();
        memset(same,0,sizeof(same));
        memset(diff,0,sizeof(diff));
        for (int j=0;j<t_size;++j)
        {
            same[0][j]= s.at(0)==t.at(j) ? 1 : 0;
            diff[0][j]= s.at(0)!=t.at(j) ? 1 : 0;
        }
        for (int i=1;i<s_size;++i)
        {
            same[i][0]= s.at(i)==t.at(0) ? 1 : 0;
            diff[i][0]= s.at(i)!=t.at(0) ? 1 : 0;
        }
        for (int i=1;i<s_size;++i)
            for (int j=1;j<t_size;++j)
                if (s.at(i)==t.at(j))
                    same[i][j]=same[i-1][j-1]+1;
        for (int i=1;i<s_size;++i)
            for (int j=1;j<t_size;++j)
            {
                if (s.at(i)==t.at(j))
                    diff[i][j]=diff[i-1][j-1];
                else
                    diff[i][j]=1+same[i-1][j-1];
            }
        int ans=0;
        for (int i=0;i<s_size;++i)
            for (int j=0;j<t_size;++j)
                ans+=diff[i][j];
        return ans;
    }
};
