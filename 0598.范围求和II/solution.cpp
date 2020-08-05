//每次都是[0,a)、[0,b)加1，那么其实就是一个包含左上角的区域不断叠加，所以求最长的最小值和宽的最小值即可
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (vector<int> &i:ops)
        {
            m=min(m,i.at(0));
            n=min(n,i.at(1));
        }
        return m*n;
    }
};
