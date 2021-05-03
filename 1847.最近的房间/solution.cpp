// 离线算法+set二分
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& roo, vector<vector<int>>& que) {
        int qsz=que.size();
        int rsz=roo.size();
        vector<int> idx(qsz),ans(qsz);
        for (int i=0;i<qsz;i++) {
            idx.at(i)=i;
        }
        sort(idx.begin(),idx.end(),[&que](const int &A,const int &B){
            return que.at(A).at(1)>que.at(B).at(1);
        });
        sort(roo.begin(),roo.end(),[](const vector<int> &A,const vector<int> &B){
            return A.at(1)>B.at(1);
        });
        int p=0;
        set<int> st;
        for (int i=0;i<qsz;i++) {
            int id=idx.at(i);
            int pi=que.at(id).at(0),mi=que.at(id).at(1);
            while (p<rsz && roo.at(p).at(1)>=mi) {
                st.insert(roo.at(p).at(0));
                p++;
            }
            auto pos=st.lower_bound(pi);
            int res=-1;
            if (pos!=st.end()) {
                res=*pos;
            }
            if (pos!=st.begin()) {
                pos--;
                int cur=*pos;
                int dc=abs(cur-pi),dp=abs(res-pi);
                if (dc<dp) {
                    res=cur;
                } else if (dc==dp) {
                    res=min(res,cur);
                }
            }
            ans.at(id)=res;
        } 
        return ans;
    }
};