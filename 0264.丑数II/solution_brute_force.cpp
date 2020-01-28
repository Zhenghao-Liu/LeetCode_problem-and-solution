class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        for (long long a=1;a<=INT_MAX;a=a*2)
            for (long long b=a;b<=INT_MAX;b=b*3)
                for (long long c=b;c<=INT_MAX;c=c*5)
                    v.push_back(c);
        sort(v.begin(),v.end());
        return v.at(n-1);
    }
};
