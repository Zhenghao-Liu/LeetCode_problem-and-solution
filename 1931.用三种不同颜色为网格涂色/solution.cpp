// 3进制状压dp
typedef long long ll;
ll mod=1e9+7;
class Solution {
    int MAXM;
public:
    int colorTheGrid(int m, int n) {
        MAXM=m;
        int all=0;
        for (int i=0;i<m;i++) {
            all+=insert(2,i);
        }
        vector<int> mask;
        for (int i=0;i<=all;i++) {
            if (check_line(i)) {
                mask.push_back(i);
            }
        }
        int sz=mask.size();
        vector<vector<ll>> dp(n,vector<ll>(sz));
        for (int i=0;i<sz;i++) {
            dp.at(0).at(i)=1;
        }
        for (int j=1;j<n;j++) {
            for (int cur=0;cur<sz;cur++) {
                for (int bef=0;bef<sz;bef++) {
                    if (check_bet(mask.at(cur),mask.at(bef))) {
                        dp.at(j).at(cur)+=dp.at(j-1).at(bef);
                        dp.at(j).at(cur)%=mod;
                    }
                }
            }
        }
        ll ans=0;
        for (int i=0;i<sz;i++) {
            ans+=dp.at(n-1).at(i);
            ans%=mod;
        }
        return ans;
    }
    int insert(int a,int n) {
        for (int i=0;i<n;i++) {
            a*=3;
        }
        return a;
    }
    bool check_line(int n) {
        int cur=n%3;
        n/=3;
        for (int i=1;i<MAXM;i++) {
            int a=n%3;
            n/=3;
            if (a==cur) {
                return false;
            }
            cur=a;
        }
        return true;
    }
    bool check_bet(int a,int b) {
        for (int i=0;i<MAXM;i++) {
            int x=a%3;
            a/=3;
            int y=b%3;
            b/=3;
            if (x==y) {
                return false;
            }
        }
        return true;
    }
};