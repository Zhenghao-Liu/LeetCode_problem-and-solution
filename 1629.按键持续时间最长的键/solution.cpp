class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int cnt[26]={0};
        int size=releaseTimes.size();
        cnt[keysPressed.at(0)-'a']=releaseTimes.at(0);
        for (int i=1;i<size;++i)
        {
            int idx=keysPressed.at(i)-'a';
            int s=releaseTimes.at(i)-releaseTimes.at(i-1);
            cnt[idx]=max(cnt[idx],s);
        }
        char ans;
        int mx=0;
        for (int i=0;i<26;++i)
            if (cnt[i]>=mx)
            {
                mx=cnt[i];
                ans=char(i+'a');
            }
        return ans;
    }
};
