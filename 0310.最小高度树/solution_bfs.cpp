//每次找出度为1的节点，摘叶子一样摘掉，减去对应边，重新找度为1节点，一层一层，最后只有可能剩一个或两个节点，即为最小高度树的根
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n==1)
            return {0};
        vector<vector<int>> mask(n);
        vector<int> road(n,0);
        for (vector<int> &i:edges)
        {
            mask.at(i.at(0)).push_back(i.at(1));
            mask.at(i.at(1)).push_back(i.at(0));
            ++road.at(i.at(0));
            ++road.at(i.at(1));
        }
        queue<int> helper;
        for (int i=0;i<n;++i)
            if (road.at(i)==1)
                helper.push(i);
        vector<int> answer;
        while (!helper.empty())
        {
            answer.clear();
            int helper_size=helper.size();
            for (int i=0;i<helper_size;++i)
            {
                int node=helper.front();
                helper.pop();
                answer.push_back(node);
                for (int &j:mask.at(node))
                {
                    --road.at(j);
                    if (road.at(j)==1)
                        helper.push(j);
                }
            }
        }
        return answer;
    }
};
