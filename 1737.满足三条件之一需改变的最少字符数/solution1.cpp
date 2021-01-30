/*
 * 三个条件是互相独立的
 * 所以互相分开讨论，只有条件一和条件二是可以互换位置同一份代码
 * 对于条件三：统计字母的出现个数然后贪心去往出现次数最多的边即可
 * 对于条件一、二：因为字母只有26种，所以可以去枚举这个分界线
 */
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
        for (int i=1;i<26;i++) {
            int cnta=0;
            for (int j=0;j<i;j++) {
                cnta+=a.at(j);
            }
            int cntb=0;
            for (int j=i;j<26;j++) {
                cntb+=b.at(j);
            }
            res=min(res,sza-cnta+szb-cntb);
        }
        return res;
    }
};
