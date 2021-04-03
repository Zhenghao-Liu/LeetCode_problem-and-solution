class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> a(n),b(n);
        for (int i=0;i<n;i++) {
            a.at(i)=i;
        }
        int ans=0;
        while (1) {
            ans++;
            for (int i=0;i<n;i++) {
                b.at(i)=a.at(i);
            }
            for (int i=0;i<n;i++) {
                if ((i%2)==0) {
                    b.at(i)=a.at(i/2);
                } else {
                    b.at(i)=a.at(n/2+(i-1)/2);
                }
            }
            int i=0;
            for (i=0;i<n;i++) {
                if (b.at(i)!=i) {
                    break;
                }
            }
            if (i==n) {
                break;
            }
            for (int i=0;i<n;i++) {
                a.at(i)=b.at(i);
            }
        }
        return ans;
    }
};