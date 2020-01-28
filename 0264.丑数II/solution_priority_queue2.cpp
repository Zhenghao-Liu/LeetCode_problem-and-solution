class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue <double,vector<double>,greater<double> > q;
        set<int> s;
        s.insert(1);
        vector<int> mask({2,3,5});
        double answer=1;
        for (int i=1;i<n;++i)
        {
            for (int &j:mask)
                if (s.count(answer*j)==0)
                {
                    q.push(answer*j);
                    s.insert(answer*j);
                }
            answer=q.top();
            q.pop();
        }
        return answer;
    }
};
