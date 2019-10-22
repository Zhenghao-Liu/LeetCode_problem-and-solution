class Solution {
public:
    int mySqrt(int x) {
        //所有平方根都小于x/2+1
        int left=0,right=x/2+1;
        long mid;
        while (left<=right)
        {
            mid=(left+right)/2;
            if ( (mid*mid==x) || ( (mid*mid<x) && ((mid+1)*(mid+1)>x) ))
                return mid;
            else if (mid*mid>x)
                right=mid-1;
            else
                left=mid+1;
        }
        //无效的return
        return left;
    }
};
