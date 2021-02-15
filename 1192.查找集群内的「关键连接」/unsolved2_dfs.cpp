/*
* 既然删了边a->b，且是桥，那么表明a集合和b集合不再是同一个集合
	表明a无法再到达b，那只需要判断删边之后a能否到达b即可，不能达到即是桥
*/
class Solution {
    vector<vector<int>> edges;
    //0表示没有删除，1表示删除，-1表示删除过了
    vector<unordered_map<int, int>> judge_delete;
    vector<bool> visit;
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        edges = vector<vector<int>>(n);
        judge_delete = vector<unordered_map<int, int>>(n);
        visit = vector<bool>(n, false);
        for (vector<int> &i : connections)
        {
            edges[i[0]].push_back(i[1]);
            judge_delete[i[0]].insert({ i[1],0 });
            edges[i[1]].push_back(i[0]);
            judge_delete[i[1]].insert({ i[0],0 });
        }
        return get_bridge_size(n);
    }
    vector<vector<int>> get_bridge_size(int n)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i)
            for (int j : edges[i])
            {
                if (judge_delete[i][j] == -1)
                    continue;
                fill(visit.begin(), visit.end(), false);
                judge_delete[i][j] = 1;
                judge_delete[j][i] = 1;
                if (!judge_i_to_j(i, j))
                    ans.push_back({i,j});
                judge_delete[i][j] = -1;
                judge_delete[j][i] = -1;
            }
        return ans;
    }
    bool judge_i_to_j(int cur, int target)
    {
        if (cur == target)
            return true;
        for (int i : edges[cur])
            if (!visit[i] && judge_delete[cur][i] != 1)
            {
                visit[i] = true;
                if (judge_i_to_j(i, target))
                    return true;
            }
        return false;
    }
};
