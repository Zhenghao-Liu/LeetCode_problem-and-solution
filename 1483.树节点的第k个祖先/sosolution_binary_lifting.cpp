/**
* Binary Lifting
* dp[node][j]存储的是节点node的距离2^j的祖先
* 转移方程dp[node][j]=dp[ dp[node][j-1] ][j-1]
  初始化dp[node][0]就是parent[node]
* 转移可以理解成node的第8个祖先，是第4个祖先节点即dp[node][2]，这个节点的第4个祖先
* 对于每一个查询 k，把 k 拆解成二进制表示，然后根据二进制表示中 1 的位置，累计向上查询。
*/
class TreeAncestor {
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int>& parent) {
        for (int i=0;i<n;++i)
            dp.push_back({parent.at(i)});
        for (int j=1;;++j)
        {
            bool all_root=true;
            for (int i=0;i<n;++i)
            {
                int t= dp.at(i).at(j-1)!=-1 ? dp.at(dp.at(i).at(j-1)).at(j-1) : -1;
                dp.at(i).push_back(t);
                if(t!=-1)
                    all_root=false;
            }
            if (all_root)
                break;
        }
    }
    
    int getKthAncestor(int node, int k) {
        int index_of_k=0;
        int cur=node;
        //比如k=6=110B
        //可以分成2^1+2^2，即dp[node][1]代表了2^1，
        //dp[node][1]=next_node，则dp[next_node][2]代表了2^2
        while (k!=0 && cur!=-1)
        {
            //剪枝，如果当前k超过了最大祖先数量那么必定是-1
            if (index_of_k>=dp.at(cur).size())
                return -1;
            if ((k&1)==1)
                cur=dp.at(cur).at(index_of_k);
            k>>=1;
            ++index_of_k;
        }
        return cur;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
