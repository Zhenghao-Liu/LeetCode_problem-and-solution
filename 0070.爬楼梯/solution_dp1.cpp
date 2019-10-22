class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
            return 1;
        vector<int> answer(n);
        answer.at(0)=1;
        answer.at(1)=2;
        for (int i=2;i<n;++i)
            answer.at(i)=answer.at(i-1)+answer.at(i-2);
        return answer.at(n-1);
    }
};
