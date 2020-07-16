//同dfs的思想，只是改成了bfs染色
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
                color.at(i)=0;
                queue<int> helper;
                helper.push(i);
                while (!helper.empty())
                {
                    int cur=helper.front();
                    helper.pop();
                    int cur_color=color.at(cur);
                    int next_color=cur_color^1;
                    for (int j:graph.at(cur))
                    {
                        if (color.at(j)==-1)
                        {
                            color.at(j)=next_color;
                            helper.push(j);
                        }
                        else
                        {
                            if (color.at(j)!=next_color)
                                return false;
                        }
                    }
                }
            }
        return true;
    }
};
