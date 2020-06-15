//如果碰到1，则在字符串末尾添加一个与结尾字符串不同的字符，遇到2则添加两个
class Solution {
public:
    int magicalString(int n) {
        if (n==0)
            return 0;
        if (n<=3)
            return 1;
        string s="122";
        int fast=2;
        int ans=1;
        for (int i=2;i<n;++i)
        {
            if (s.at(i)=='1')
            {
                ++ans;
                if (s.at(fast)=='1')
                    s+="2";
                else
                    s+="1";
                ++fast;
            }
            else
            {
                if (s.at(fast)=='1')
                    s+="22";
                else
                    s+="11";
                fast+=2;
            }
        }
        return ans;
    }
};
