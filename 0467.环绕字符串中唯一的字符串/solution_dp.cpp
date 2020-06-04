/*
* 采用滑窗和dp思想
* dp[i]看成以每个字符结尾，满足"···zab···xyzab···"的序列有多长
* 因为不能重复，所以只用记录最长的情况即可
* 最终求和即是所有符合题目的子字符串
*/
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> dp(26,0);
        int window=0;
        int p_size=p.size();
        for (int i=0;i<p_size;++i)
        {
            if (i>0 && check_continuous(p.at(i-1),p.at(i)))
                ++window;
            else
                window=1;
            int index=p.at(i)-'a';
            dp.at(index)=max(dp.at(index),window);
        }
        int ans=0;
        for (int &i:dp)
            ans+=i;
        return ans;
    }
    bool check_continuous(char &prev,char &cur)
    {
        if (prev=='z')
            return cur=='a';
        return prev+1==cur;
    }
};
