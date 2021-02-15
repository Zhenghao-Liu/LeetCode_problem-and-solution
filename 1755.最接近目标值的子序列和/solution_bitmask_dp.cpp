/*
 * 40的数据量，显然是分成两份20，然后分别采用2^20复杂度
 * 之后两边可以像两数之和一样去枚举最接机目标值的元素：一个大于等于一个小于，共两个目标值即可
 * 为了查找效率采用二分
 */
const int MAXN=20;
int dp[1<<MAXN];
class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int sz=nums.size();
        if (sz==1) {
            return min(abs(nums.at(0)-goal),abs(goal));
        }
        int mid=sz/2;
        vector<int> left(nums.begin(),nums.begin()+sz/2);
        int lSz=left.size();
        solve(left);
        int leftALL=(1<<lSz)-1;
        set<int> st;
        for (int i=0;i<=leftALL;i++) {
            st.insert(dp[i]);
        }
        vector<int> right(nums.begin()+sz/2,nums.end());
        int rSz=right.size();
        int rightALL=(1<<rSz)-1;
        solve(right);
        int ans=INT_MAX;
        for (int i=0;i<=rightALL;i++) {
            int cur=dp[i];
            int tar=goal-cur;
            auto p=st.lower_bound(tar);
            if (p!=st.end()) {
                ans=min(ans,abs(cur+*p-goal));
            }
            if (p!=st.begin()) {
                p--;
                ans=min(ans,abs(cur+*p-goal));
            }
        }
        return ans;
    }
    void solve(vector<int> &vec) {
        int sz=vec.size();
        int ALL=(1<<sz)-1;
        dp[0]=0;
        for (int i=1;i<=ALL;i++) {
            for (int j=0;j<32;j++) {
                int mask=1<<j;
                if ((i&mask)!=0) {
                    dp[i]=dp[i^mask]+vec.at(j);
                    break;
                }
            }
        }
    }
};
