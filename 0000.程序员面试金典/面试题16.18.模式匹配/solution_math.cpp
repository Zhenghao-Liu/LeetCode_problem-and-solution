/*
* count_a个'a',长设为x
* count_b个'b',长设为y
* 则x*count_a+y*count_y=value_size，于是枚举x或者y即可
* 注意a、b可以为空串，且a、b不能匹配相同字符串
* 枚举x、y之后建立起a、b匹配的字符串，通过快慢指针方式匹配即可
*/
class Solution {
public:
    bool patternMatching(string pattern, string value) {
        int pattern_size=pattern.size();
        int count_a=0;
        for (char &i:pattern)
            if (i=='a')
                ++count_a;
        int count_b=pattern_size-count_a;
        int value_size=value.size();
        vector<string> dict(2);
        for (int x=0;x<=value_size;++x)
        {
            int y= count_b==0 ? 0 : (value_size-count_a*x)/count_b;
            if (y<0)
                break;
            if (count_b*y+count_a*x!=value_size)
                continue;
            fill(dict.begin(),dict.end(),"");
            int slow=0,fast=0;
            bool judge=true;
            for (;slow<pattern_size;++slow)
            {
                if (pattern.at(slow)=='a')
                {
                    if (dict.at(0).size()!=x)
                        dict.at(0)=value.substr(fast,x);
                    else if (dict.at(0)!=value.substr(fast,x))
                    {
                        judge=false;
                        break;
                    }
                    fast+=x;
                }
                //else if (pattern.at(slow)=='b')
                else
                {
                    if (dict.at(1).size()!=y)
                        dict.at(1)=value.substr(fast,y);
                    else if (dict.at(1)!=value.substr(fast,y))
                    {
                        judge=false;
                        break;
                    }
                    fast+=y;
                }
            }
            if (count_a*count_b>0 && dict.at(0)!=dict.at(1) && judge)
                return true;
            else if (count_a*count_b<=0 && judge)
                return true;
        }
        return false;
    }
};
