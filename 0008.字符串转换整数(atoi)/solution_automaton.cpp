//状态机
class automaton
{
private:
    string state="start";
    unordered_map<string,vector<string>> mask{
        {"start",{"start","signed","in_number","end"}},
        {"signed",{"end","end","in_number","end"}},
        {"in_number",{"end","end","in_number","end"}},
        {"end",{"end","end","end","end"}}
    };
public:
    int sign=1;
    long long ans=0;
    int get_index(char & c)
    {
        if (c==' ')
            return 0;
        if (c=='+' || c=='-')
            return 1;
        if (c>='0' && c<='9')
            return 2;
        return 3;
    }
    void helper(char & c)
    {
        state=mask.at(state).at(get_index(c));
        if (state=="signed")
            sign=c=='+' ? 1 : -1;
        else if (state=="in_number")
        {
            ans=ans*10-'0'+c;
            if (sign==1)
                ans=min(ans,(long long)INT_MAX);
            else
                ans=min(ans,-(long long)INT_MIN);
        }
    }
};
class Solution {
public:
    int myAtoi(string str) {
        automaton dp;
        for (char & i:str)
            dp.helper(i);
        return dp.ans*dp.sign;
    }
};
