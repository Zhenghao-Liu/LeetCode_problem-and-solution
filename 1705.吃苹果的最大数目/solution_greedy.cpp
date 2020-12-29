// 贪心：每天都吃最快要过期的苹果，直到没有苹果可以吃
typedef pair<int,int> pii;
class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int ans=0;
        int size=apples.size();
        for (int i=0;!pq.empty() || i<size;i++) {
            while (!pq.empty() && pq.top().first<i) {
                pq.pop();
            }
            int a=i<size ? apples.at(i) : 0;
            int d=i<size ? days.at(i) : 0;
            if (a!=0 && d!=0) {
                pq.push({i+d-1,a});
            }
            if (!pq.empty()) {
                auto [ed,ap]=pq.top();
                pq.pop();
                ++ans;
                if (ap-1!=0) {
                    pq.push({ed,ap-1});
                }
            }
        }
        return ans;
    }
};
