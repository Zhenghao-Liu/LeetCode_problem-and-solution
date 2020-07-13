/*
* 堆优化的迪杰斯特拉
* 因为边权值是在0<=x<=1的范围，所以可以直接求
  但是如果精度要求过高可以转换成对数，这样将相乘变成相加
*/
typedef pair<int,double> pii;
class Solution {
    vector<vector<pii>> edges;
public:
    double maxProbability(int n, vector<vector<int>>& _edges, vector<double>& succProb, int start, int end) {
        vector<bool> use(n,false);
        use.at(start)=true;
        edges=vector<vector<pii>>(n);
        int size=_edges.size();
        for (int i=0;i<size;++i)
        {
            edges.at(_edges.at(i).at(0)).push_back({_edges.at(i).at(1),succProb.at(i)});
            edges.at(_edges.at(i).at(1)).push_back({_edges.at(i).at(0),succProb.at(i)});
        }
        priority_queue<pair<double,int>> p;
        for (auto &i:edges.at(start))
        {
            p.push({i.second,i.first});
        }
        while (!p.empty())
        {
            auto [x,y]=p.top();
            p.pop();
            if (use.at(y))
                continue;
            use.at(y)=true;
            if (y==end)
                return x;
            for (auto &i:edges.at(y))
                if (!use.at(i.first))
                    p.push({i.second*x,i.first});
        }
        return 0;
    }
};
