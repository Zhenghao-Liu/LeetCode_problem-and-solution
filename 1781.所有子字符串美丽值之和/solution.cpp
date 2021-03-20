class Solution {
public:
    int beautySum(string s) {
        int sz=s.size();
        int ans=0;
        for (int i=0;i<sz;i++) {
            int cnt[26]={0};
            for (int j=i;j<sz;j++) {
                cnt[s.at(j)-'a']++;
                int mx=0;
                int mi=INT_MAX;
                for (int k=0;k<26;k++) {
                    mx=max(mx,cnt[k]);
                    if (cnt[k]!=0) {
                        mi=min(mi,cnt[k]);
                    }
                }
                ans+=mx-mi;
            }
        }
        return ans;
    }
};
