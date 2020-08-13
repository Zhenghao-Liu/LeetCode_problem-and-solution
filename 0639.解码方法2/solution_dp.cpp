//字符'*'可以被当做1到9当中的任意一个数字
class Solution {
    int mod=1e9+7;
public:
    int numDecodings(string s) {
        int s_size=s.size();
        vector<int> dp(s_size+1,0);
        dp.at(0)=1;
        if (s.at(0)=='0')
            return 0;
        dp.at(1)= s.at(0)=='*' ? 9 : 1;
        for (int i=2;i<=s_size;++i)
        {
            if (s.at(i-1)=='*')
            {
                dp.at(i)+=dp.at(i-1)*9;
                dp.at(i)%=mod;
                if (s.at(i-2)=='1')
                {
                    dp.at(i)+=dp.at(i-2)*9;
                    dp.at(i)%=mod;
                }
                else if (s.at(i-2)=='2')
                {
                    dp.at(i)+=dp.at(i-2)*6;
                    dp.at(i)%=mod;
                }
                else if (s.at(i-2)=='*')
                {
                    dp.at(i)+=dp.at(i-2)*9;
                    dp.at(i)%=mod;
                    dp.at(i)+=dp.at(i-2)*6;
                    dp.at(i)%=mod;
                }
            }
            else if (s.at(i-1)=='0')
            {
                if (s.at(i-2)=='1' || s.at(i-2)=='2')
                {
                    dp.at(i)+=dp.at(i-2);
                    dp.at(i)%=mod;
                }
                else if (s.at(i-2)=='*')
                {
                    dp.at(i)+=dp.at(i-2)*2;
                    dp.at(i)%=mod;
                }
                else
                    return 0;
            }
            //else if (s.at(i-1)>='1' && s.at(i-1)<='9')
            else
            {
                dp.at(i)+=dp.at(i-1);
                dp.at(i)%=mod;
                if (s.at(i-2)=='1')
                {
                    dp.at(i)+=dp.at(i-2);
                    dp.at(i)%=mod;
                }
                else if (s.at(i-2)=='2' && s.at(i-1)<='6')
                {
                    dp.at(i)+=dp.at(i-2);
                    dp.at(i)%=mod;
                }
                else if (s.at(i-2)=='*')
                {
                    dp.at(i)+=dp.at(i-2);
                    dp.at(i)%=mod;
                    if (s.at(i-1)<='6')
                    {
                        dp.at(i)+=dp.at(i-2);
                        dp.at(i)%=mod;
                    }
                }
            }
        }
        return dp.at(s_size);
    }
};
