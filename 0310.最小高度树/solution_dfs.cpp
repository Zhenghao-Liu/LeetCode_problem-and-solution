//方法来源:评论区：[心](https://leetcode-cn.com/u/xin-96/)
//最小高度树的根节点一定是图当中最远一段距离的中点
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> mask(n);
        for (vector<int> &i:edges)
        {
            mask.at(i.at(0)).push_back(i.at(1));
            mask.at(i.at(1)).push_back(i.at(0));
        }
        vector<int> road(n,0);
        //先从0节点开始dfs找到离0节点最远的节点node1
        road.at(0)=1;
        int node1=dfs(mask,road,0);
        //再从离0节点最远的节点node1开始，dfs找到离node1最远的距离
        road=vector<int>(n,0);
        road.at(node1)=1;
        int node2=dfs(mask,road,node1);
        //纪录下node2到node1所经过所有节点
        vector<int> past_through;
        past_through.push_back(node2);
        int temp=node2;
        while (node2!=node1)
            for (int &i:mask.at(node2))
                if (road.at(i)+1==road.at(node2))
                {
                    past_through.push_back(i);
                    node2=i;
                    break;
                }
        int past_through_size=past_through.size();
        //假若路程一共经过偶数个节点，那答案是最中间两个
        if (past_through_size%2==0)
            return {past_through.at(past_through_size/2),past_through.at(past_through_size/2-1)};
        //倘若路程经过奇数个节点，答案是最中间节点
        //else if (past_through_size%2==1)
        return {past_through.at(past_through_size/2)};

    }
    int dfs(vector<vector<int>> & mask,vector<int> & road,int node)
    {
        int farthest_node=node;
        for (int &i:mask.at(node))
            if (road.at(i)==0)
            {
                road.at(i)=road.at(node)+1;
                int temp=dfs(mask,road,i);
                if (road.at(temp)>road.at(farthest_node))
                    farthest_node=temp;
            }
        return farthest_node;
    }
};
