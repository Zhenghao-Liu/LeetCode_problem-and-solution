typedef long long ll;
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int l=1,r=maxSum;
        while (l<r) {
            ll mid=l+(r-l+1)/2;
            ll leftNum=index,rightNum=n-1-index;
            ll leftCan=min(leftNum,mid-1),rightCan=min(rightNum,mid-1);
            ll sum=mid;
            sum+=(leftNum-leftCan)+leftCan*(mid-leftCan+mid-1)/2;
            sum+=(rightNum-rightCan)+rightCan*(mid-rightCan+mid-1)/2;
            if (sum<=maxSum) {
                l=mid;
            } else {
                r=mid-1;
            }
        }
        return l;
    }
};