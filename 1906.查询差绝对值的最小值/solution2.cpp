/*
 * 存入每个值的所有出现下标
 * 在[l,r]的范围内，通过二分判断值val是否有出现在该区间内
 */
const int MAXV=100+1;
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int sz1=nums.size(),sz2=queries.size();
        vector<int> cnt[MAXV];
        for (int i=0;i<sz1;i++) {
            int num=nums.at(i);
            cnt[num].push_back(i);
        }
        vector<int> ans(sz2,-1);
        for (int i=0;i<sz2;i++) {
            int l=queries.at(i).at(0),r=queries.at(i).at(1);
            int pre=0;
            int val=1;
            int res=INT_MAX/2;
            for (val=1;val<MAXV;val++) {
                auto mi=lower_bound(cnt[val].begin(),cnt[val].end(),l);
                if (mi==cnt[val].end()) {
                    continue;
                }
                auto mx=lower_bound(mi,cnt[val].end(),r);
                if (!(
                    (mx!=cnt[val].end() && (*mx)==r) || 
                    (mx!=mi && (*prev(mx,1))<=r)
                    )) {
                    continue;
                }
                if (pre==0) {
                    pre=val;
                    continue;
                }
                res=min(res,val-pre);
                pre=val;
            }
            ans.at(i)= res==INT_MAX/2 ? -1 : res;
        }
        return ans;
    }
};