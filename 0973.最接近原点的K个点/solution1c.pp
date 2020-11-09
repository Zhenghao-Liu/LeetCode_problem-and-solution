typedef pair<int,int> pii;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto func=[](const pii &A,const pii &B)->bool{
            int dis_A=abs(A.first)*abs(A.first)+abs(A.second)*abs(A.second);
            int dis_B=abs(B.first)*abs(B.first)+abs(B.second)*abs(B.second);
            return dis_A<dis_B;
        };
        priority_queue<pii,vector<pii>,decltype(func)> pq(func);
        for (vector<int> &i:points)
        {
            pq.push({i.at(0),i.at(1)});
            if ((int)pq.size()>K)
                pq.pop();
        }
        vector<vector<int>> ans;
        ans.reserve(K);
        while (!pq.empty())
        {
            auto [x,y]=pq.top();
            pq.pop();
            ans.push_back({x,y});
        }
        return ans;
    }
};
