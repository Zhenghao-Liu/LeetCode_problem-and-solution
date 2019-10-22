static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int myAtoi(string str) {
        int length=str.size();
        if (0==length)
            return 0;
        string ans="";
        int begin=0,judge=0;
        for (int i=0;i<length;++i)
            if (str.at(i)==' '||str.at(i)=='    ')
                continue;
            else
            {
                judge=int(str.at(i));
                if (judge!=43 && judge!=45 && judge<48 && judge>57 )
                    return 0;
                else
                {
                    begin=i;
                    break;
                }
            }
        if (str.at(begin)=='-')
        {
            ans='-';
            ++begin;
        }
        else if (str.at(begin)=='+')
        {
            ans='+';
            ++begin;
        }
        else
            ans='+';
        for (int i=begin;i<length;++i)
        {
            judge=int(str.at(i));
            if (judge<58 && judge >47)
                ans=ans+str.at(i);
            else
                break;
        }
        int ans_length=ans.size(),truth_length=ans.size();
        for (int i=1;i<ans_length;++i)
            if (ans.at(i)=='0')
            {
                --truth_length;
                continue;
            }
            else
                break;                
        long long answer=0;
        if (ans_length==1)
            return 0;
        else if (truth_length>12 && ans.at(0)=='+')
            return INT_MAX;
        else if (truth_length>12 && ans.at(0)=='-')
            return INT_MIN;
        else
            for (int i=ans_length-1,j=0;i>ans_length-truth_length;--i,++j)
                answer=answer+long(pow(10,j))*(int(ans.at(i))-48);
        if (ans.at(0)=='-')
            answer=-1*answer;
        if (answer>INT_MAX)
            return INT_MAX;
        else if (answer<INT_MIN)
            return INT_MIN;
        else
            return answer;          
    }
};
