/*
* 既然要求是每条边的两个节点都属于不同集合
* 可以从一点出发然后进行染色，将该点周围的点染成与该点不同的颜色
* 但是没有说是连通图，所以要判断所有节点是否都遍历到了
*/
class Solution {
    //-1表示未分配，分配则为0或1
    vector<int> color;
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int size=graph.size();
        color=vector<int>(size,-1);
        for (int i=0;i<size;++i)
            if (color.at(i)==-1)
            {
                //设默认集合为0
                color.at(i)=0;
                bool judge=dfs(graph,i);
                if (!judge)
                    return false;
            }
        return true;
    }
    bool dfs(vector<vector<int>> & graph,int cur)
    {
        int cur_color=color.at(cur);
        int next_color=cur_color^1;
        for (int j:graph.at(cur))
        {
            if (color.at(j)==-1)
            {
                color.at(j)=next_color;
                bool judge=dfs(graph,j);
                if (!judge)
                    return false;
            }
            else
            {
                if (color.at(j)!=next_color)
                    return false;
            }
        }
        return true;
    }
};
