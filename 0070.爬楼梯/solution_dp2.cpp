class Solution {
public:
    int climbStairs(int n) {
        if (n==1)
            return 1;
        //节省了下空间，算法本质一样
        int answer=2,left=1,right=2;
        for (int i=2;i<n;++i)
        {
            answer=left+right;
            left=right;
            right=answer;
        }
        return answer;
    }
};
