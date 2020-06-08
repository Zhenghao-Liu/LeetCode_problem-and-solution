//(rand7()-1)*7+rand7()可以生成1~49的随机数，那么只要>10都不要重新生成即可
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ans=(rand7()-1)*7+rand7();
        while (ans>10)
            ans=(rand7()-1)*7+rand7();
        return ans;
    }
};
