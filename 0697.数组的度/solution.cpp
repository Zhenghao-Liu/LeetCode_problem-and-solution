/*
* 要求子数组的度要和原数组一样
* 首先要统计出满足要求的度，以及对应的字母
* 那么要想最短，既然是要包含该字母，自然起点就是该字母第一次出现的位置，终点就是字母最后一次出现的位置
* 但是满足度有可能有多个字母，所以都要考虑，取最小值
*/
const int MAXN=50000;
int cnt[MAXN];
int pos_start[MAXN];
int pos_end[MAXN];
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        memset(cnt,0,sizeof(cnt));
        memset(pos_start,0,sizeof(pos_start));
        memset(pos_end,0,sizeof(pos_end));
        int nums_size=nums.size();
        int max_cnt=0;
        for (int i=0;i<nums_size;++i)
        {
            int ii=nums.at(i);
            if (cnt[ii]==0)
                pos_start[ii]=i;
            pos_end[ii]=i;
            ++cnt[ii];
            max_cnt=max(max_cnt,cnt[ii]);
        }
        int ans=INT_MAX;
        for (int i=0;i<MAXN;++i)
            if (cnt[i]==max_cnt)
                ans=min(ans,pos_end[i]-pos_start[i]+1);
        return ans;
    }
};
