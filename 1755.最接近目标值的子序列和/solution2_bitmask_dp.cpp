// 采用同样的状压方式，但是后面求结果可以先排序，之后采用双指针的形式
const int MAXN=20;
int dp1[1<<MAXN];
int dp2[1<<MAXN];
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
        int leftALL=(1<<lSz)-1;
        solve1(left);
        vector<int> right(nums.begin()+sz/2,nums.end());
        int rSz=right.size();
        int rightALL=(1<<rSz)-1;
        solve2(right);
        int lp=0,rp=rightALL;
        int ans=INT_MAX;
        while (lp<=leftALL && rp>=0) {
            int sum=dp1[lp]+dp2[rp];
            ans=min(ans,abs(sum-goal));
            if (ans==0) {
                return ans;
            }
            if (sum>goal) {
                rp--;
            } else {
                lp++;
            }
        }
        return ans;
    }
    void solve1(vector<int> &vec) {
        int sz=vec.size();
        int ALL=(1<<sz)-1;
        dp1[0]=0;
        for (int i=1;i<=ALL;i++) {
            for (int j=0;j<32;j++) {
                int mask=1<<j;
                if ((i&mask)!=0) {
                    dp1[i]=dp1[i^mask]+vec.at(j);
                    break;
                }
            }
        }
        sort(dp1,dp1+ALL+1);
    }
    void solve2(vector<int> &vec) {
        int sz=vec.size();
        int ALL=(1<<sz)-1;
        dp2[0]=0;
        for (int i=1;i<=ALL;i++) {
            for (int j=0;j<32;j++) {
                int mask=1<<j;
                if ((i&mask)!=0) {
                    dp2[i]=dp2[i^mask]+vec.at(j);
                    break;
                }
            }
        }
        sort(dp2,dp2+ALL+1);
    }
};
