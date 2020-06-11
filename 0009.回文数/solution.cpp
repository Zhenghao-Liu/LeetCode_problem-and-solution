//求x的一半是否和另外一半相同
//但要注意x的长度是奇数的情况，或者x只有一位数的情况
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0 || (x%10==0 && x!=0))
            return false;
	    int reverse_x=0;
        while (x>reverse_x)
        {
            reverse_x=reverse_x*10+x%10;
            x/=10;
        }
        return reverse_x==x || x==reverse_x/10;
    }
};
