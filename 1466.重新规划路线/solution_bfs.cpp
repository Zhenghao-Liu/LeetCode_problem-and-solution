/*
* 因为每个节点间只有一条路，其实要想保证都能到0，修改方案只有一种
* 那么存每个节点，但是只按题意方向存是不够的
  因为要改变路线，可能要反着方向去走
  所以存取路线时候用pair.second来表示方向，a->b则对于a来说pair.second为1，对于b来说pair.second为0
* 要想所有节点到达0，可以反过来，从0通过反向到达所有节点
* 所以从0开始bfs遍历所有节点，如果是正向即pair.second为1说明此路线需要反向，++ans
*/
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n,false);
        vector<vector<pair<int,int>>> edges(n);
        for (vector<int> &i:connections)
        {
            int from=i.at(0);
            int to=i.at(1);
            edges.at(from).push_back({to,1});
            edges.at(to).push_back({from,0});
        }
        vis.at(0)=true;
        queue<int> helper;
        helper.push(0);
        int ans=0;
        while (!helper.empty())
        {
            int pos=helper.front();
            helper.pop();
            for (pair<int,int> &i:edges.at(pos))
            {
                if (vis.at(i.first))
                    continue;
                vis.at(i.first)=true;
                helper.push(i.first);
                if (i.second==1)
                    ++ans;
            }
        }
        return ans;
    }
};
