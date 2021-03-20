typedef pair<int,int> pii;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int ext) {
        auto func=[](const pii &A,const pii &B){
            return 1.0*(A.first+1)/(A.second+1)-1.0*(A.first)/(A.second)
                <1.0*(B.first+1)/(B.second+1)-1.0*(B.first)/(B.second);
        };
        priority_queue<pii,vector<pii>,decltype(func)> pq(func);
        int one=0;
        for (vector<int> &i:classes) {
            if (i.at(0)==i.at(1)) {
                one++;
                continue;
            }
            pq.push({i.at(0),i.at(1)});
        }
        if (pq.empty()) {
            return 1;
        }
        while (ext!=0) {
            auto [x,y]=pq.top();
            pq.pop();
            pq.push({x+1,y+1});
            ext--;
        }
        double ans=0;
        while (!pq.empty()) {
            auto [x,y]=pq.top();
            pq.pop();
            ans+=1.0*x/y;
        }
        ans+=one;
        return 1.0*ans/classes.size();
    }
};
