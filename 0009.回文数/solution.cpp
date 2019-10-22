static const auto SpeedUp = []{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();
class Solution {
public:
    bool isPalindrome(int x) {
	    if (x<0)
            return false;
        if (x==0)
            return true;
        int wei,num=x;
	    for (wei=0;wei<=10;++wei)
		    if (num==0)
			    break;
		    else
			    num=num/10;
	    long long ans=0,y=x;
        for (int i=wei-1;i>=0;--i)
	    {
		    ans=(x%10)*pow(10,i)+ans;
		    x=x/10;
	    }
	    if (ans==y)
            return true;
        else
            return false;
    }
};
