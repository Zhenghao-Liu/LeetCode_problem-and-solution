//数据量很小，所以可以爆搜，但是这题实际上是很有难度的，可以看下题解的分析
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        set<string> ans;
        ans.insert(s);
        queue<string> que;
        que.push(s);
        int size=s.size();
        while (!que.empty())
        {
            string cur,cur2;
            cur=cur2=que.front();
            que.pop();
            for (int i=1;i<size;i+=2)
            {
                int n=cur.at(i)-'0';
                n=(n+a)%10;
                cur.at(i)=char(n+'0');
            }
            if (ans.find(cur)==ans.end())
            {
                ans.insert(cur);
                que.push(cur);
            }
            string t;
            t.reserve(size);
            for (int i=size-b;i<size;++i)
                t+=cur2.at(i);
            for (int i=0;i<size-b;++i)
                t+=cur2.at(i);
            if (ans.find(t)==ans.end())
            {
                ans.insert(t);
                que.push(t);
            }
        }
        return *ans.begin();
    }
};
