class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans;
        int sz=s.size();
        int mx=0;
        for (int i=0;i<sz;i++) {
            int j=i;
            int cnt1[26]={0};
            int cnt2[26]={0};
            for (int j=i;j<sz;j++) {
                char cur=s.at(j);
                if (cur>='a' && cur<='z') {
                    cnt1[cur-'a']++;
                } else {
                    cnt2[cur-'A']++;
                }
                bool flag=true;
                for (int k=0;k<26;k++) {
                    if ((cnt1[k]==0 && cnt2[k]==0) || (cnt1[k]!=0 && cnt2[k]!=0)) {
                        continue;
                    } else {
                        flag=false;
                        break;
                    }
                }
                if (flag && j-i+1>mx) {
                    ans=s.substr(i,j-i+1);
                    mx=j-i+1;
                }
            }
        }
        return ans;
    }
};
