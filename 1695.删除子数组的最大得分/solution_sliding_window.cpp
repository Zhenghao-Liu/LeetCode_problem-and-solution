const int MAXN=1e4+1;
int cnt[MAXN];
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        memset(cnt,0,sizeof(cnt));
        int ans=0;
        int size=nums.size();
        int r=0;
        int sum=0;
        sum+=nums.at(0);
        cnt[nums.at(0)]++;
        for (int l=0;l<size;++l)
        {
            while (r+1<size && cnt[nums.at(r+1)]==0)
            {
                ++r;
                sum+=nums.at(r);
                cnt[nums.at(r)]++;
            }
            ans=max(ans,sum);
            --cnt[nums.at(l)];
            sum-=nums.at(l);
        }
        return ans;
    }
};
