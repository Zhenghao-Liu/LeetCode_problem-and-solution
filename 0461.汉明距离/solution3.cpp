//相比于法2移动的更快
class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor_ans=x^y;
        int ans=0;
        while (xor_ans!=0)
        {
            ++ans;
            //这个会消除最末尾的1位1
            xor_ans&=xor_ans-1;
        }
        return ans;
    }
};
