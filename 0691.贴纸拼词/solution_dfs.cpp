/*
* 记忆化dfs
* 和顺序无关，只和出现的字母的次数有关
*/
const int MAXN=50;
int stikers_count[MAXN][26];
class Solution {
    int stickers_size;
    //记忆化dfs
    unordered_map<string,int> min_use;
public:
    int minStickers(vector<string>& stickers, string target) {
        memset(stikers_count,0,sizeof(stikers_count));
        stickers_size=stickers.size();
        for (int i=0;i<stickers_size;++i)
            for (char j:stickers.at(i))
                ++stikers_count[i][j-'a'];
        min_use.clear();
        min_use[""]=0;
        return dfs(target);
    }
    int dfs(string target)
    {
        if (min_use.find(target)!=min_use.end())
            return min_use.at(target);
        int cur_min_use=INT_MAX;
        int cur_count[26];
        memset(cur_count,0,sizeof(cur_count));
        for (char i:target)
            ++cur_count[i-'a'];
        string s;
        int ans=INT_MAX;
        for (int i=0;i<stickers_size;++i)
        {
            //剪枝，如果都不含target的首字母，那么该stickers[i]消除不了首字母
            if (stikers_count[i][target.at(0)-'a']==0)
                continue;
            s.clear();
            for (int j=0;j<26;++j)
            {
                int c=cur_count[j]-stikers_count[i][j];
                if (c>0)
                    s.append(c,'a'+j);
            }
            int try_ans=dfs(s);
            if (try_ans!=-1)
                ans=min(ans,try_ans+1);
        }
        min_use[target]= ans==INT_MAX ? -1 : ans;
        return min_use[target];
    }
};
