/*
 * 将n-1位序列作为节点，共有k^(n-1)个节点，每个节点入度出度均为k
 * 那么总共有k^(n-1)*k个n位长的序列，即符合题意
 * 因为度均为偶数，所以是个欧拉图，也必然有欧拉回路
 * 先选择起点，然后出发进行DFS，把走过的边都删掉。
   无路可走的点压进栈内。
   把栈里的点都pop出来，就是一条欧拉路径。
 */
class Solution {
    unordered_set<int> memo;
    int mask;
    int k;
    string ans;
public:
    string crackSafe(int n, int _k) {
        memo.clear();
        mask=pow(10,n-1);
        k=_k;
        ans.clear();
        dfs(0);
        ans+=string(n-1,'0');
        return ans;
    }
    void dfs(int cur)
    {
        for (int num=0;num<k;++num)
        {
            int nxt=cur*10+num;
            if (memo.find(nxt)==memo.end())
            {
                memo.insert(nxt);
                dfs(nxt%mask);
                ans+=char(num+'0');
            }
        }
    }
};
