class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int n=salary.size()-2;
        int sum=0;
        for (int i=1;i<=n;++i)
            sum+=salary.at(i);
        return double(sum)/n;
    }
};
