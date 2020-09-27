//先拆分成每个单词，然后遇到括号就递归，记录新变量和旧变量之间的替换
//v->e
class Solution {
    unordered_map<string,int> var;
    int NOT_EXIST=INT_MAX/2;
public:
    int evaluate(string expression) {
        var.clear();
        return dfs(expression);
    }
    int dfs(string &s)
    {
        vector<string> apart;
        take_apart(s,apart);
        int apart_size=apart.size();
        int ans=0;
        unordered_map<string,int> ori_var;
        if (apart.at(0)=="let")
        {
            for (int i=1;i+1<apart_size;i+=2)
            {
                string v=apart.at(i),e=apart.at(i+1);
                //记录旧的值
                if (ori_var.find(v)==ori_var.end())
                {
                    if (var.find(v)!=var.end())
                        ori_var[v]=var.at(v);
                    else
                        ori_var[v]=NOT_EXIST;
                }
                //替换成新的值
                if (e.at(0)=='(')
                    var[v]=dfs(e);
                else if (e.at(0)>='a' && e.at(0)<='z')
                    var[v]=var[e];
                else
                    var[v]=stoi(e);
            }
            string expr=apart.back();
            if (expr.at(0)=='(')
                ans=dfs(expr);
            else
            {
                if (var.find(expr)!=var.end())
                    ans=var.at(expr);
                else
                    ans=stoi(expr);
            }
        }
        //else if (apart.at(0)=="add" || apart.at(0)=="mult")
        else
        {
            string v[2];
            v[0]=apart.at(1),v[1]=apart.at(2);
            int e[2];
            for (int i=0;i<2;++i)
            {
                if (v[i].at(0)=='(')
                    e[i]=dfs(v[i]);
                else
                {
                    if (var.find(v[i])!=var.end())
                        e[i]=var.at(v[i]);
                    else
                        e[i]=stoi(v[i]);
                }
            }
            if (apart.at(0)=="add")
                ans=e[0]+e[1];
            //else if (apart.at(0)=="mult")
            else
                ans=e[0]*e[1];
        }
        //恢复成旧的值
        for (auto &[v,e]:ori_var)
            if (e==NOT_EXIST)
                var.erase(var.find(v));
            else
                var.at(v)=e;
        return ans;
    }
    void take_apart(string &s,vector<string> & apart)
    {
        int left=0;
        int start=0;
        int size=s.size();
        if (s.at(0)=='(')
            ++start;
        for (int i=start;i<size;++i)
        {
            if (left==0 && (s.at(i)==' ' || s.at(i)==')'))
            {
                apart.push_back(s.substr(start,i-start));
                start=i+1;
            }
            if (s.at(i)=='(')
                ++left;
            else if (s.at(i)==')')
                --left;
        }
    }
};
