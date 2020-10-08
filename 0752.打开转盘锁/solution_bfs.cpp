//BFS找最短路径
const int MAXN=10000;
int vis[MAXN];
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        memset(vis,0,sizeof(vis));
        for (string &i:deadends)
            vis[stoi(i)]=1;
        int ans=-1;
        if (vis[0]==1)
            return -1;
        int tar=stoi(target);
        string s;
        queue<int> helper;
        helper.push(0);
        vis[0]=1;
        while(!helper.empty())
        {
            int size=helper.size();
            ++ans;
            for (int i=0;i<size;++i)
            {
                int num=helper.front();
                helper.pop();
                if (num==tar)
                    return ans;
                s=to_string(num);
                if (s.size()<4)
                    s.insert(s.begin(),4-s.size(),'0');
                for (int j=0;j<4;++j)
                {
                    char c=s.at(j);
                    if (c=='9')
                        s.at(j)='0';
                    else
                        s.at(j)=char(c+1);
                    int n=stoi(s);
                    if (vis[n]==0)
                    {
                        vis[n]=1;
                        helper.push(n);
                    }
                    if (c=='0')
                        s.at(j)='9';
                    else
                        s.at(j)=char(c-1);
                    n=stoi(s);
                    if (vis[n]==0)
                    {
                        vis[n]=1;
                        helper.push(n);
                    }
                    s.at(j)=c;
                }
            }
        } 
        return -1;
    }
};
