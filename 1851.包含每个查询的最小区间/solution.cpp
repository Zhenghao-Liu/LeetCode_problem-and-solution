/*
 * 离线+堆，长度最小的出堆
 * 因为是离线，保证了左边界一定满足，所以还需要检测右边界是否满足
 */
typedef pair<int,int> pii;
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& val, vector<int>& que) {
        int vsz=val.size();
        int qsz=que.size();
        vector<int> ans(qsz,-1),idx(qsz);
        for (int i=0;i<qsz;i++) {
            idx.at(i)=i;
        }
        sort(idx.begin(),idx.end(),[&que](const int &A,const int &B){
            return que.at(A)<que.at(B);
        });
        sort(val.begin(),val.end());
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int st=0;
        for (int i=0;i<qsz;i++) {
            int ii=idx.at(i);
            int q=que.at(ii);
            while (st<vsz && val.at(st).at(0)<=q) {
                int l=val.at(st).at(0),r=val.at(st).at(1);
                pq.push({r-l+1,r});
                st++;
            }
            while (!pq.empty() && pq.top().second<q) {
                pq.pop();
            }
            if (!pq.empty()) {
                ans.at(ii)=pq.top().first;
            }
        }
        return ans;
    }
};