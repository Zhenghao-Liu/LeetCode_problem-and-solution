class Solution {
public:
    string validIPAddress(string IP) {
        if (check_ipv4(IP))
            return "IPv4";
        if (check_ipv6(IP))
            return "IPv6";
        return "Neither";
    }
    bool check_ipv4(string & s)
    {
        string window;
        //统计有几个'.'
        int count=0;
        int s_size=s.size();
        for (int i=0;i<=s_size;++i)
        {
            if (i==s_size || s.at(i)=='.')
            {
                ++count;
                if (count==4 && i!=s_size && s.at(i)=='.')
                    return false;
                if (window.empty() || window.size()>3)
                    return false;
                int num=stoi(window);
                if (window.size()>1 && window.at(0)=='0')
                    return false;
                window.clear();
                if (!(num>=0 && num<=255))
                    return false;
            }
            else if (s.at(i)>='0' && s.at(i)<='9')
            {
                window+=s.at(i);
            }
            else
                return false;
        }
        return count==4;
    }
    bool check_ipv6(string & s)
    {
        string window;
        int count=0;
        int s_size=s.size();
        for (int i=0;i<=s_size;++i)
        {
            if (i==s_size || s.at(i)==':')
            {
                ++count;
                if (count==8 && i!=s_size && s.at(i)==':')
                    return false;
                if (window.empty() || window.size()>4)
                    return false;
                window.clear();
            }
            else if ((s.at(i)>='0' && s.at(i)<='9') || (s.at(i)>='a' && s.at(i)<='f') || (s.at(i)>='A' && s.at(i)<='F'))
            {
                window+=s.at(i);
            }
            else
                return false;
        }
        return count==8;
    }
};
