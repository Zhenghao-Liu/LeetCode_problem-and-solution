//要想最后是aaabbb情况，求出每个字母左边有几个b，右边有几个a，然后取最小即可
class Solution {
public:
    int minimumDeletions(string s) {
        int size=s.size();
        vector<int> a(size);
        vector<int> b(size);
        a.at(0)=s.at(0)=='a' ? 0 : 1;
        for (int i=1;i<size;++i)
            a.at(i)= s.at(i)=='a' ? a.at(i-1) : a.at(i-1)+1;
        b.at(size-1)=s.at(size-1)=='b' ? 0 : 1;
        for (int i=size-2;i>=0;--i)
            b.at(i)= s.at(i)=='b' ? b.at(i+1) : b.at(i+1)+1;
        int ans=size-1;
        for (int i=0;i<size;++i)
        {
            int l= i==0 ? 0 : a.at(i-1);
            int r= i==size-1 ? 0 : b.at(i+1);
            ans=min(ans,l+r);
        }
        return ans;
    }
};
