/*
* 换个思路，设可以移动T次，有K个鸡蛋，能满足找到F的最高层数N是多少
* 即N=f(T,K) 求出所有的N，找到f(T,K)>=题目所给N的最小值T
* 倘若a层扔了一个鸡蛋，若没碎，即f(T-1,K)，则表明F在a的上层，则上方有f(T-1,K)层
                     若蛋碎，则f(T-1,K-1)，则表明F在a的下层，则下方有f(T-1,K-1)层
  加上a这一层
  dp.at(i).at(j)=1+dp.at(i-1).at(j-1)+dp.at(i-1).at(j);
* 对于K=1即只有一个鸡蛋，移动T次可以满足T层，即f(T,1)=T
* 对于T=1即只能移动一次，那多少个鸡蛋都只能检查出1层
* 那么可移动次数T的限制大小是多少？只能得知移动次数必定小于等于层数，因为最坏的情况就是一个鸡蛋，这时移动次数等于层数
* 我们只需要在找到第一个f(T,K)>=N的第一个T即是答案
* 注意初始化时一行一行操作
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        if (N==1)
            return 1;
        vector<vector<int>> dp(N+1,vector<int>(K+1,0));
        for (int i=1;i<=K;++i)
            dp.at(1).at(i)=1;
        for (int i=2;i<=N;++i)
            for (int j=1;j<=K;++j)
            {
                dp.at(i).at(j)=1+dp.at(i-1).at(j-1)+dp.at(i-1).at(j);
                if (dp.at(i).at(j)>=N)
                    return i;
            }
        return -1;
    }
};
