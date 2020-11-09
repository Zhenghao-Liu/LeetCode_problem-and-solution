//阶梯下降
class Solution {
public:
    int minDeletions(string s) {
        vector<int> cnt(26,0);
        for (char i:s)
            ++cnt.at(i-'a');
        sort(cnt.rbegin(),cnt.rend());
        int ans=0;
        for (int i=1;i<26;++i)
            while (cnt.at(i)>0 && cnt.at(i-1)<=cnt.at(i))
            {
                --cnt.at(i);
                ++ans;
            }
        return ans;
    }
};
