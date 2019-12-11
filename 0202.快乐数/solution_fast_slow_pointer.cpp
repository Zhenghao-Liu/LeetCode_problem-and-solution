//如果不是快乐数，则会陷入循环状态，那fast会出现等于slow
class Solution {
public:
    bool isHappy(int n) {
        int slow=n,fast=get_num(n);
        while (fast!=slow)
        {
            slow=get_num(slow);
            fast=get_num(fast);
            fast=get_num(fast);
        }
        return fast==1;
    }
    int get_num(int n)
    {
        int answer=0;
        while (n!=0)
        {
            answer=answer+pow(n%10,2);
            n=n/10;
        }
        return answer;
    }
};
