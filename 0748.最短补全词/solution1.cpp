//模拟
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int cnt[26]={0};
        for (char &i:licensePlate)
            if (is_letter(i))
                ++cnt[i-'a'];
        int words_cnt[26];
        string ans;
        for (string &i:words)
        {
            memset(words_cnt,0,sizeof(words_cnt));
            for (char &c:i)
                ++words_cnt[c-'a'];
            int j=0;
            for (;j<26;++j)
                if (words_cnt[j]<cnt[j])
                    break;
            if (j==26 && (ans.empty() || i.size()<ans.size()))
                ans=i;
        }
        return ans;
    }
    bool is_letter(char &c)
    {
        //判断是否字母顺便大写变小写
        if (c>='A' && c<='Z')
        {
            c=c+'a'-'A';
            return true;
        }
        else if (c>='a' && c<='z')
            return true;
        return false;
    }
};
