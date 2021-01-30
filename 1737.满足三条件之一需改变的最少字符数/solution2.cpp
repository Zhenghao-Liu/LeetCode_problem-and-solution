// 枚举条件一、二的分界线时可以用前缀和取优化
class Solution {
public:
    int minCharacters(string a, string b) {
        vector<int> cnt(26);
        vector<int> cnta(26);
        for (char i:a) {
            cnt.at(i-'a')++;
            cnta.at(i-'a')++;
        }
        vector<int> cntb(26);
        for (char i:b) {
            cnt.at(i-'a')++;
            cntb.at(i-'a')++;
        }
        int sza=a.size();
        int szb=b.size();
        int ans=sza+szb-*max_element(cnt.begin(),cnt.end());
        ans=min(ans,helper(cnta,cntb,sza,szb));
        ans=min(ans,helper(cntb,cnta,szb,sza));
        return ans;
    }
    int helper(vector<int> &a,vector<int> &b,int sza,int szb) {
        int res=INT_MAX/2;
        int cnta=0;
        int cntb=accumulate(b.begin(),b.end(),0);
        for (int i=1;i<26;i++) {
            cnta+=a.at(i-1);
            cntb-=b.at(i-1);
            res=min(res,sza-cnta+szb-cntb);
        }
        return res;
    }
};
