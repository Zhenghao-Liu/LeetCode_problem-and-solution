class Solution {
public:
    int thirdMax(vector<int>& nums) {
        //a>b>c
        long long a,b,c;
        a=b=c=(long long)INT_MIN-1;
        for (int &i:nums)
            if (i==a || i==b || i==c || i<c)
                continue;
            else if (i>a)
            {
                c=b;
                b=a;
                a=i;
            }
            else if (i>b && i<a)
            {
                c=b;
                b=i;
            }
            else if (i>c && i<b)
            {
                c=i;
            }
        return c+1==INT_MIN ? a : c;
    }
};
