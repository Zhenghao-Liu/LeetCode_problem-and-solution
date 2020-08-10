class Solution {
public:
    string makeGood(string s) {
        int size=s.size();
        string ans;
        for (int i=0;i<size;++i)
        {
            ans.push_back(s.at(i));
            int ans_size=ans.size();
            while (ans_size>=2 && judge(ans.at(ans_size-1),ans.at(ans_size-2)))
            {
                ans.pop_back();
                ans.pop_back();
                ans_size-=2;
            }
        }
        return ans;
    }
    bool judge(char a,char b)
    {
        return a==b+'a'-'A' || b==a+'a'-'A';
    }
};
