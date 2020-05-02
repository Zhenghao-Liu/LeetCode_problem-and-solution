class Solution {
public:
    string decodeString(string s) {
        //frist表数字前存储的字符串
        //second表[]前的数字
        stack<pair<string,int>> helper_stack;
        string window;
        string num;
        int s_size=s.size();
        for (char &i:s)
        {
            if (i>='0' && i<='9')
                num+=i;
            else if (i=='[')
            {
                helper_stack.push({window,stoi(num)});
                window.clear();
                num.clear();
            }
            else if (i==']')
            {
                string temp;
                for (int j=helper_stack.top().second;j>0;--j)
                    temp+=window;
                window=helper_stack.top().first;
                helper_stack.pop();
                window+=temp;
            }
            else
                window+=i;
        }
        return window;
    }
};
