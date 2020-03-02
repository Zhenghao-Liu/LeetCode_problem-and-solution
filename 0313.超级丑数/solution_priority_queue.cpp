class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int primes_size=primes.size();
        priority_queue<double,vector<double>,greater<double>> helper;
        helper.push(1);
        int answer;
        for (int i=0;i<n;++i)
        {
            answer=helper.top();
            helper.pop();
            while (!helper.empty() && answer==helper.top())
                helper.pop();
            for (int & j:primes)
                helper.push(1.0*answer*j);
        }
        return answer;
    }
};
