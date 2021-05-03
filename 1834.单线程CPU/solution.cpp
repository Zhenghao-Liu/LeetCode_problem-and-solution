typedef long long ll;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int sz=tasks.size();
        vector<int> vec(sz);
        for (int i=0;i<sz;i++) {
            vec.at(i)=i;
        }
        sort(vec.begin(),vec.end(),[&tasks](const int &A,const int &B){
            return tasks.at(A).at(0)<tasks.at(B).at(0);
        });
        auto func=[&tasks](const int &A,const int &B)->bool{
            return tasks.at(A).at(1)==tasks.at(B).at(1) ? A>B : tasks.at(A).at(1)>tasks.at(B).at(1);
        };
        priority_queue<int,vector<int>,decltype(func)> pq(func);
        vector<int> ans;
        ans.reserve(sz);
        ll cur=1;
        int idx=0;
        while (!pq.empty() || idx<sz) {
            while (idx<sz && tasks.at(vec.at(idx)).at(0)<=cur) {
                pq.push(vec.at(idx));
                idx++;
            }
            if (pq.empty() && idx<sz) {
                cur=tasks.at(vec.at(idx)).at(0);
                continue;
            }
            int pop=pq.top();
            ans.push_back(pop);
            pq.pop();
            ll a=tasks.at(pop).at(0),b=tasks.at(pop).at(1);
            cur=max(cur+b,a+b);
        }
        return ans;
    }
};