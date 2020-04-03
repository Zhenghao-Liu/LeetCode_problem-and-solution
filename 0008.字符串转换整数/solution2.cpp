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
        //int begin=index;
        for (;index<str_size && str.at(index)>='0' && str.at(index)<='9';++index)
        {
            //更新了判断条件,这里注意当读进数为INT_MIN时也被直接return了
            int temp=str.at(index)-'0';
            if (ans>INT_MAX/10 || (ans==INT_MAX/10 && temp>7))
                return sign==1 ? INT_MAX : INT_MIN;
            ans=ans*10-'0'+str.at(index);
        }
        ans=sign*ans;
        return ans;
    }
};
