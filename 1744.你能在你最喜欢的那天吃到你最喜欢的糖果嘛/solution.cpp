/*
 * 到第i天，最少要吃i+1颗糖果，最多可以吃(i+1)*daliyCapi颗糖果
 * 只需要保证最少吃的情况不会吃完目的种类的糖果
   且最多吃的情况能把前面所有种类吃完，且至少还有1次机会能吃目的种类糖果
 * 上下界都满足则代表可以吃到喜欢的糖果
 */
typedef long long ll;
class Solution {
public:
    vector<bool> canEat(vector<int>& cancnt, vector<vector<int>>& que) {
        int sz=cancnt.size();
        vector<ll> cnt(cancnt.begin(),cancnt.end());
        for (int i=1;i<sz;i++) {
            cnt.at(i)+=cnt.at(i-1);
        }
        int len=que.size();
        vector<bool> ans(len);
        for (int i=0;i<len;i++) {
            int typ=que.at(i).at(0);
            int day=que.at(i).at(1);
            int cap=que.at(i).at(2);
            ll up=(ll)(day+1)*cap;
            ll mi=(ll)(day+1);
            ll cur=(ll)cnt.at(typ);
            ll pre=typ-1>=0 ? cnt.at(typ-1) : 0;
            if (up>pre && mi<=cur) {
                ans.at(i)=true;
            }
        }
        return ans;
    }
};
