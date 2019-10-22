//[G(n)函数的值被称为 卡塔兰数 Cn](https://leetcode-cn.com/problems/unique-binary-search-trees/solution/bu-tong-de-er-cha-sou-suo-shu-by-leetcode/)
class Solution {
public:
    int numTrees(int n) {
        long C = 1;
        for (int i = 0; i < n; ++i)
            C = C * 2 * (2 * i + 1) / (i + 2);
        return (int) C;
    }
};
