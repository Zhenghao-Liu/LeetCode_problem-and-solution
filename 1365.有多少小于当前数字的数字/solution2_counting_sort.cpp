const int MAXN=101;
int cnt[MAXN];
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        memset(cnt,0,sizeof(cnt));
        for (int i:nums)
            ++cnt[i];
        for (int i=1;i<MAXN;++i)
            cnt[i]+=cnt[i-1];            
        vector<int> ans;
        int nums_size=nums.size();
        ans.reserve(nums_size);
        for (int i:nums)
        {
            if (i-1>=0)
                ans.push_back(cnt[i-1]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};
