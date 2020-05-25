//通过找没有出现在p中字符作为分界线剪枝，以及长度剪枝
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_size=s.size();
        int p_size=p.size();
        if (s_size<p_size)
            return {};
        vector<int> p_show_times(26,0);
        for (char &i:p)
            ++p_show_times.at(i-'a');
        vector<int> pos;
        for (int i=0;i<s_size;++i)
            if (p_show_times.at(s.at(i)-'a')==0)
                pos.push_back(i);
        pos.push_back(s_size);
        int start=0;
        vector<int> ans;
        for (int &i:pos)
        {
            helper(s,p_show_times,p_size,start,i-1,ans);
            start=i+1;
        }
        return ans;
    }
    //[start,end]
    void helper(string &s,const vector<int> & p_show_times,const int & p_size,int start,int end,vector<int> &ans)
    {
        if (end-start+1<p_size)
            return;
        vector<int> window(26,0);
        int count=0;
        for (int i=start;i<=end;++i)
        {
            if (count>=p_size)
                --window.at(s.at(i-p_size)-'a');
            ++count;
            ++window.at(s.at(i)-'a');
            if (count>=p_size)
            {
                bool judge=true;
                for (int j=0;j<26;++j)
                    if (p_show_times.at(j)!=window.at(j))
                    {
                        judge=false;
                        break;
                    }
                if (judge)
                    ans.push_back(i+1-p_size);
            }
        }
        return;
    }
};
