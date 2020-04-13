/*
* 贝祖定理：明了对任何整数a、b和它们的最大公约数d，ax + by = m
           有解当且仅当m是d的倍数。裴蜀等式有解时必然有无穷多个整数解
* 每次操作只会给水的总量带来 x 或者 y 的变化量。因此我们的目标可以改写成：找到一对整数 a, b，使得ax+by=z
* 所以求z是否是gcd(x,y)倍数
*/
class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+y<z)
            return false;
        if (z==0 || x+y==z || y==z || x==z)
            return true;
        return z % gcd(x,y) ==0;

    }
};
