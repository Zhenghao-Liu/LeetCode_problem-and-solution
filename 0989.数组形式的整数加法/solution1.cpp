const int MAXN=1e4+1;
class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> ans;
        ans.reserve(MAXN);
        int i=A.size()-1;
        int carry=0;
        while (i>=0 || K>0) {
            int a= i>=0 ? A.at(i) : 0;
            int b= K%10;
            int sum=a+b+carry;
            ans.push_back(sum%10);
            carry=sum/10;
            i--;
            K/=10;
        }
        if (carry==1) {
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
