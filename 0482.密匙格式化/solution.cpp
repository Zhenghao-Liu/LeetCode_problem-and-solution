class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        string ans;
        int count=0;
        int S_size=S.size();
        ans.reserve(S_size*2);
        for (int i=S_size-1;i>=0;--i)
            if (S.at(i)!='-')
            {
                if (S.at(i)>='a' && S.at(i)<='z')
                    ans+=char(S.at(i)-('a'-'A'));
                else
                    ans+=S.at(i);
                ++count;
                if (count==K)
                {
                    count=0;
                    ans+='-';
                }
            }
        if (!ans.empty() && ans.back()=='-')
            ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
