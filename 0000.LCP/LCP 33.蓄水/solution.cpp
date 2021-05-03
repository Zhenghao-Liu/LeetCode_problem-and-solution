// 去枚举总共要倒几次水
class Solution {
public:
    int storeWater(vector<int>& buc, vector<int>& vat) {
        int ans=0;
        int sz=vat.size();
        for (int i=0;i<sz;i++) {
            if (buc.at(i)==0 && vat.at(i)!=0) {
                buc.at(i)++;
                ans++;
            }
        }
        int mx=*max_element(vat.begin(),vat.end());
        if (mx==0) {
            return 0;
        }
        int res=INT_MAX;
        for (int i=1;i<=mx;i++) {
            int cur=0;
            for (int j=0;j<sz;j++) {
                int a=vat.at(j)/i;
                if (a*i!=vat.at(j)) {
                    a++;
                }
                cur+=max(a-buc.at(j),0);
            }
            res=min(res,cur+i);
        }
        return ans+res;
    }
};