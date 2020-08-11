class Solution {
public:
    bool judgeSquareSum(int c) {
        int i=0,j=(int)sqrt(c);
        while (i<=j)
        {
            long long res=(long long)i*i+j*j;
            if (res==c)
                return true;
            else if (res>c)
                --j;
            else if (res<c)
                ++i;
        }
        return false;
    }
};
