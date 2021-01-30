// 草稿纸弄到30就知道规律了就是1 12 123 1234 12345
class Solution {
public:
    int minimumBoxes(int n) {
        int ans=0;
        int sum=1;
        int cnt=1;
        while (n-sum>0) {
            n-=sum;
            ans+=cnt;
            cnt++;
            sum+=cnt;
        }
        for (int i=1;i<=cnt;i++) {
            n-=i;
            ans++;
            if (n<=0) {
                break;
            }
        }
        return ans;
    }
};
