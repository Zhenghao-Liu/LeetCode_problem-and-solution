class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int ans=0;
        vector<int> v{a,b,c};
        int zero=0;
        while (check(v)) {
            sort(v.rbegin(),v.rend());
            v.at(0)--;
            v.at(1)--;
            ans++;
        }
        return ans;
    }
    int check(vector<int> &v) {
        int zero=0;
        for (int i:v) {
            if (i==0) {
                zero++;
            }
        }
        return zero<2;
    }
};
