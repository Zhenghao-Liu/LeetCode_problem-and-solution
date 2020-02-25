class Solution {
public:
    int reverse(int x) {
        int sign=x>=0?1:-1;
        long long long_x=abs((long long)x);
        string s=to_string(long_x);
	//手撕reverse(s.begin(),s.end());
        auto first=s.begin(),last=s.end();
        while ((first!=last)&&(first!=--last))
        {
            std::iter_swap(first,last);
            ++first;
        }
        long_x=stoll(s)*sign;
        return long_x>INT_MAX || long_x<INT_MIN ? 0 : long_x;
    }
};
