typedef pair<int,int> pii;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int tar) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int sz=times.size();
        for (int i=0;i<sz;i++) {
            pq.push(i);
        }
        priority_queue<pii,vector<pii>,greater<pii>> pq2;
        vector<int> idx(sz);
        for (int i=0;i<sz;i++) {
            idx.at(i)=i;
        }
        sort(idx.begin(),idx.end(),[&times](const int &A,const int &B){
            return times.at(A).at(0)<times.at(B).at(0);
        });
        for (int i:idx) {
            int arr=times.at(i).at(0),lea=times.at(i).at(1);
            while (!pq2.empty() && pq2.top().first<=arr) {
                auto [lt,st]=pq2.top();
                pq2.pop();
                pq.push(st);
            }
            int st=pq.top();
            pq.pop();
            if (i==tar) {
                return st;
            }
            pq2.push({lea,st});
        }
        return -1;
    }
};