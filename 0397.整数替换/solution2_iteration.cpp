class Solution {
public:
    int integerReplacement(unsigned int n) {
        return helper(n);
    }
    int helper(unsigned int n) {
        if (n==1)
            return 0;
        int ans=0;
        while (n!=1)
        {
            //偶数时必然/2
            if ((n&1)==0)
                n>>=1;
            //奇数则需要+1 -1取优
            //策略就是尽可能的在二进制中减少1的位数，即尽可能多出现0
            else
            {
                //既然是奇数最后一位必然是1
                //那倒数第二位就对选+1 -1有影响
                //倘若是···11B 那么选择+1
                //倘若是···01B 那么选择-1
                if ((n&0b10)==0)
                    --n;
                //3是一个特例3->4->2->1 和 3->2->1虽然他是结尾是11但是他-1更优
                else if (n==3)
                    --n;
                else
                    ++n;
            }
            ++ans;
        }
        return ans;
    }
};
