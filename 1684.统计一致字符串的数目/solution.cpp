class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int cnt[26]={0};
        for (char i:allowed)
            ++cnt[i-'a'];
        int ans=0;
        for (string &i:words)
        {
            bool flag=true;
            for (char j:i)
                if (cnt[j-'a']==0)
                {
                    flag=false;
                    break;
                }
            if (flag)
                ++ans;
        }
        return ans;
    }
};
