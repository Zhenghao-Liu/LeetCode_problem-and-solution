//求出所有子序列，若出现次数为1，则是特殊序列
class Solution {
    unordered_map<string,int> count;
public:
    int findLUSlength(vector<string>& strs) {
        count.clear();
        for (string &i:strs)
        {
            string cur;
            dfs(i,0,cur);
        }
        int ans=-1;
        for (auto &i:count)
            if (i.second==1)
                ans=max(ans,(int)i.first.size());
        return ans;
    }
    void dfs(string & s,int begin,string &cur)
    {
        if (!cur.empty())
            ++count[cur];
        int s_size=s.size();
        if (begin>s_size)
            return;
        for (int i=begin;i<s_size;++i)
        {
            cur+=s.at(i);
            dfs(s,i+1,cur);
            cur.pop_back();
        }
    }
};
