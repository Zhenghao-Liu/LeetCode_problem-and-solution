typedef pair<int,int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pii>> edges(N+1);
        for (vector<int> &i:times)
            edges.at(i.at(0)).push_back({i.at(1),i.at(2)});
        vector<bool> vis(N+1,false);
        vector<int> dis(N+1,INT_MAX/2);
        auto func=[](const pii &A,const pii &B)->bool{return A.second>B.second;};
        priority_queue<pii,vector<pii>,decltype(func)> pq(func);
        pq.push({K,0});
        dis.at(K)=0;
        while (!pq.empty())
        {
            auto [cur,val]=pq.top();
            pq.pop();
            if (vis.at(cur))
                continue;
            vis.at(cur)=true;
            for (auto &[nxt,nxt_val]:edges.at(cur))
                if (dis.at(nxt)>val+nxt_val)
                {
                    dis.at(nxt)=val+nxt_val;
                    pq.push({nxt,dis.at(nxt)});
                }
        }
        int ans=*max_element(dis.begin()+1,dis.end());
        return ans==INT_MAX/2 ? -1 : ans;
    }
};
