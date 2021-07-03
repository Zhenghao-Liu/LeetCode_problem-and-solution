/*
 * 一个二维数组竖着的前缀和
 * cnt[i][j]表示第i位时（从0开始），值为j的个数
 * 这样子就可以通过前缀和cnt[r+1][val]-cnt[l][val]
   判断在[l,r]这个区间内，是否有val这个数字
 * 因为1 <= nums[i] <= 100，可以去扫描值
 * 且绝对值最小，一定是排序后相邻差的最小值
 */
const int MAXN=1e5;
const int MAXV=100+1;
int cnt[MAXN+1][MAXV];
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int sz1=nums.size(),sz2=queries.size();
        memset(cnt,0,sizeof(cnt));
        for (int i=0;i<sz1;i++) {
            int num=nums.at(i);
            cnt[i+1][num]++;
            for (int j=1;j<MAXV;j++) {
                cnt[i+1][j]+=cnt[i][j];
            }
        }
        vector<int> ans(sz2,-1);
        for (int i=0;i<sz2;i++) {
            int l=queries.at(i).at(0),r=queries.at(i).at(1);
            int pre=0;
            int val=1;
            int res=INT_MAX/2;
            for (val=1;val<MAXV;val++) {
                if (cnt[r+1][val]-cnt[l][val]>0) {
                    if (pre==0) {
                        pre=val;
                        continue;
                    }
                    res=min(res,val-pre);
                    pre=val;
                }
            }
            ans.at(i)= res==INT_MAX/2 ? -1 : res;
        }
        return ans;
    }
};