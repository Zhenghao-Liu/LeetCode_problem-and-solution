class Solution {
public:
    int myAtoi(string str) {
        int str_size=str.size();
        int index=0;
        while (index<str_size && str.at(index)==' ')
            ++index;
        if (index==str_size)
            return 0;
        int sign;
        if (str.at(index)=='+' || str.at(index)=='-')
        {
            sign=str.at(index)=='+' ? 1 : -1;
            ++index;
        }
        else if (str.at(index)>='0' && str.at(index)<='9')
            sign=1;
        else
            return 0;
        while (index<str_size && str.at(index)=='0')
            ++index;
        long long ans=0;
        int begin=index;
        for (;index<str_size && str.at(index)>='0' && str.at(index)<='9';++index)
        {
            ans=ans*10-'0'+str.at(index);
            if (index-begin+1>10)
            {
                if (sign==1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
        }
        ans=sign*ans;
        if (ans>INT_MAX)
            return INT_MAX;
        else if (ans<INT_MIN)
            return INT_MIN;
        return ans;
    }
};
