/*
 * 因为是最少次数，肯定是bfs
 * 且从终点跳回起点
 * 不能连续往左跳两次，所以需要两个vis数组，代表是往后跳到的，还是往前面一次到的
 * 还要记录当前跳的前一跳是往前跳还是往后跳
 */
// first是位置，second是否往前跳了
const int MAXN=4001;
int ba1[MAXN];
// 是否往后的形式到过
int ba0[MAXN];
typedef pair<int,int> pii;
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if (x==0)
            return 0;
        memset(ba0,0,sizeof(ba0));
        memset(ba1,0,sizeof(ba0));
        ba0[x]=1;
        for (int i:forbidden)
            ba0[i]=ba1[i]=-1;
        int ans=0;
        queue<pii> que;
        que.push({x,0});
        while (!que.empty())
        {
            ++ans;
            int size=que.size();
            for (int i=0;i<size;++i)
            {
                auto [pos,bac]=que.front();
                que.pop();
                int l=pos-a;
                if (l==0)
                    return ans;
                if (l>=0 && ba0[l]==0)
                {
                    ba0[l]=1;
                    que.push({l,0});
                }
                int r=pos+b;
                if (bac==0)
                {
                    if (r==0)
                        return ans;
                    if (r<MAXN && ba1[r]==0)
                    {
                        que.push({r,1});
                        ba1[r]=1;
                    }
                }
            }
        }
        return -1;
    }
};
