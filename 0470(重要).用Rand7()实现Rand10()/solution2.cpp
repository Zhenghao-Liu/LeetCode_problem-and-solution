/*
* (rand7()-1)*7+rand7()可以生成1~49的随机数，那么只要>10都不要重新生成即可
*但是方法一会抛弃11~49这有点多
*不如抛弃41~49，这样1~40只要取余(取个位上的数)即可
*/
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int ans=(rand7()-1)*7+rand7();
        while (ans>40)
            ans=(rand7()-1)*7+rand7();
        return 1+ans%10;
    }
};
