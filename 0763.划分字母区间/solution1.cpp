class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int cnt[26]={0};
        int size=S.size();
        for (char c:S)
            ++cnt[c-'a'];
        int start=-1;
        int cur[26]={0};
        for (int i=0;i<size;++i)
        {
            int idx=S.at(i)-'a';
            ++cur[idx];
            int j;
            for (j=0;j<26;++j)
                if (cur[j]!=0 && cnt[j]!=cur[j])
                    break;
            if (j==26)
            {
                ans.push_back(i-start);
                start=i;
                memset(cur,0,sizeof(cur));
            }
        }
        return ans;
    }
};
