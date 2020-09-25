//如果遇到括号，那就去递归求括号里面的即可
class Solution {
public:
    string countOfAtoms(string formula) {
        map<string,int> cnt=dfs(formula);
        string ans;
        for (auto &i:cnt)
        {
            ans+=i.first;
            if (i.second>1)
                ans+=to_string(i.second);
        }
        return ans;
    }
    map<string,int> dfs(string formula)
    {
        map<string,int> cnt;
        map<string,int> bracket;
        string element;
        int num=0;
        int size=formula.size();
        for (int i=0;i<=size;++i)
        {
            char c= i==size ? 'A' : formula.at(i);
            if (is_capital(c) || c=='(')
            {
                if (!element.empty())
                {
                    cnt[element]+= num==0 ? 1 : num;
                }
                if (c=='(')
                {
                    int j=i+1;
                    int left=1;
                    while (j<size)
                    {
                        if (formula.at(j)=='(')
                            ++left;
                        else if (formula.at(j)==')')
                            --left;
                        if (left==0)
                            break;
                        ++j;
                    }
                    bracket=dfs(formula.substr(i+1,j-1-i));
                    num=0;
                    ++j;
                    while (j<size && is_num(formula.at(j)))
                    {
                        num=num*10+(formula.at(j)-'0');
                        ++j;
                    }
                    num= num==0 ? 1 : num;
                    for (auto &k:bracket)
                    {
                        k.second*=num;
                        cnt[k.first]+=k.second;
                    }
                    i=j-1;
                }
                element.clear();
                num=0;
                if (c!='(')
                    element+=c;
            }
            else if (is_num(c))
            {
                num=num*10+(c-'0');
            }
            else
            {
                element+=c;
            }
        }
        return cnt;
    }
    bool is_capital(char c)
    {
        return c>='A' && c<='Z';
    }
    bool is_num(char c)
    {
        return c>='0' && c<='9';
    }
};
