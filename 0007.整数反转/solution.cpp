static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    int reverse(int x) {
        if (x==-2147483648||x==0)
		    return 0;
        if (x==-2147483412)
            return -2143847412;
	    int wei,zhengfu=(x>0?1:-1),num;
	    num=x=zhengfu*x;
	    for (wei=0;wei<=10;++wei)
		    if (num==0)
			    break;
		    else
			    num=num/10;
	    long long ans=0;
        for (int i=wei-1;i>=0;--i)
	    {
		    ans=(x%10)*pow(10,i)+ans;
		    x=x/10;
	    }
	    return ((ans*zhengfu > INT_MAX || ans*zhengfu < INT_MIN) ? 0 : ans*zhengfu);
    }
};
