//注意n=INT_MAX情况
class Solution {
public:
    int integerReplacement(unsigned int n) {
        return helper(n);
    }
    int helper(unsigned int n) {
        if (n==1)
            return 0;
        if ((n&1)==0)
            return 1+helper(n>>1);
        else
            return 1+min(helper(n+1),helper(n-1));
    }
};
