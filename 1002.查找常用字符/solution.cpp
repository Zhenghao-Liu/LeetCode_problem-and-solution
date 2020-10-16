//查找每个元素对应字母出现最少次数，即是每个元素都具有的字母
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int res[26];
        memset(res,0x3f,sizeof(res));
        int cnt[26];
        for (string &i:A)
        {
            memset(cnt,0,sizeof(res));
            for (char c:i)
                ++cnt[int(c-'a')];
            for (int j=0;j<26;++j)
                res[j]=min(res[j],cnt[j]);
        }
        vector<string> ans;
        for (int i=0;i<26;++i)
        {
            string s;
            s+=char('a'+i);
            for (int j=0;j<res[i];++j)
                ans.push_back(s);
        }
            
        return ans;
    }
};
