typedef pair<int,int> pii;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int size=points.size();
        vector<vector<pii>> edge(size);
        for (int i=0;i<size;++i)
            for (int j=i+1;j<size;++j)
            {
                int d=abs(points.at(j).at(0)-points.at(i).at(0))+abs(points.at(j).at(1)-points.at(i).at(1));
                edge.at(i).push_back({j,d});
                edge.at(j).push_back({i,d});
            }
        vector<bool> use(size,false);
        auto func=[](const pii &A,const pii &B){
            return A.second>B.second;
        };
        priority_queue<pii,vector<pii>,decltype(func)> pq(func);
        //设起点是points[0]
        use.at(0)=true;
        for (pii &i:edge.at(0))
            pq.push(i);
        int ans=0;
        int cnt=0;
        while (!pq.empty())
        {
            auto [to,dis]=pq.top();
            pq.pop();
            if (use.at(to))
                continue;
            ans+=dis;
            ++cnt;
            use.at(to)=true;
            if (cnt==size-1)
                return ans;
            for (pii &i:edge.at(to))
                pq.push(i);
        }
        return ans;
    }
};
