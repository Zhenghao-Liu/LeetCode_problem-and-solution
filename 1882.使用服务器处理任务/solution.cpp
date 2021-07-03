typedef pair<int,int> pii;
class Solution {
public:
    vector<int> assignTasks(vector<int>& ser, vector<int>& tas) {
        int sz1=ser.size(),sz2=tas.size();
        auto func=[&ser](const int &A,const int &B) {
            return ser.at(A)==ser.at(B) ? A>B : ser.at(A)>ser.at(B);
        };
        priority_queue<int,vector<int>,decltype(func)> pq(func);
        for (int i=0;i<sz1;i++) {
            pq.push(i);
        }
        auto func2=[](const pii &A,const pii &B) {
            return A.second>B.second;
        };
        priority_queue<pii,vector<pii>,decltype(func2)> can(func2);
        queue<int> que;
        vector<int> ans(sz2,-1);
        for (int i=0;i<sz2 || !que.empty();i++) {
            if (i<sz2) {
                que.push(i);
            }
            if (i>=sz2 && !can.empty()) {
                i=can.top().second;
            }
            while (!can.empty() && can.top().second<=i) {
                int c=can.top().first;
                can.pop();
                pq.push(c);
            }
            while (!pq.empty() && !que.empty()) {
                int t=que.front();
                que.pop();
                int cho=pq.top();
                pq.pop();
                ans.at(t)=cho;
                can.push({cho,i+tas.at(t)});
            }
        }
        return ans;
    }
};