class Solution {
public:
    string thousandSeparator(int n) {
        string nn=to_string(n);
        string ans;
        int size=nn.size();
        int count=0;
        for (int i=size-1;i>=0;--i)
        {
            ++count;
            ans+=nn.at(i);
            if (count==3)
            {
                count=0;
                ans+=".";
            }
        }
        if (ans.back()=='.')
            ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
