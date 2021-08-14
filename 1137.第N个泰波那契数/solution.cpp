class Solution {
public:
    int tribonacci(int n) {
        if (n==0) {
            return 0;
        }
        if (n<=2) {
            return 1;
        }
        vector<int> vec{0,1,1};
        for (int i=3;i<=n;i++) {
            int sz=vec.size();
            int num=0;
            for (int j=sz-1;sz-j<=3;j--) {
                num+=vec.at(j);
            }
            vec.push_back(num);
        }
        return vec.back();
    }
};