//能构成0的只有5和一个偶数，偶数一大堆，所以只用找5就可以了，具体推倒看题解
class Solution {
public:
    int trailingZeroes(int n) {
        int answer=0;
        while (n!=0)
        {
            n=n/5;
            answer=answer+n;
        }
        return answer;
    }
};
