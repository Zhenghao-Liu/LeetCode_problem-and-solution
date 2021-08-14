class Solution {
public:
    int countTriples(int n) {
        int ans=0;
        for (int a=1;a<=n;a++) {
            for (int b=1;b<=n;b++) {
                int sum=a*a+b*b;
                int c=sqrt(sum);
                if (c<=n && c*c==sum) {
                    ans++;
                }
            }
        }
        return ans;
    }
};