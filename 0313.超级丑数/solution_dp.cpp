//整体思路和[264.丑数II](https://github.com/Zhenghao-Liu/LeetCode_problem-and-solution/tree/master/0264.丑数II)一样
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int primes_size=primes.size();
        vector<int> index(primes_size,0);
        vector<int> dp(n);
        dp.at(0)=1;
        for (int i=1;i<n;++i)
        {
            int temp=INT_MAX;
            for (int j=0;j<primes_size;++j)
                temp=min(temp,primes.at(j)*dp.at(index.at(j)));
            for (int j=0;j<primes_size;++j)
                if (temp==primes.at(j)*dp.at(index.at(j)))
                    ++index.at(j);
            dp.at(i)=temp;
        }
        return dp.at(n-1);
    }
};
