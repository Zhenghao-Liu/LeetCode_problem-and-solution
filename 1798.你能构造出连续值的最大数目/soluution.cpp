/*
 * 假设现在有连续的区间[a,b]，再加上一个数x
   则区间会变成[a+x,b+x]
 * 现在要求连续，只要前面断了后面也就不用考虑
 * 所以只要保证[a,b]与[a+x,b+x]是连续的即可
 */
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(),coins.end());
        int mx=0;
        for (int i:coins) {
            if (i>mx+1) {
                break;
            }
            mx+=i;
        }
        return mx+1;
    }
};