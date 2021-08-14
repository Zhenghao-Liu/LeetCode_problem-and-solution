class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int sz=mat.size();
        vector<int> vec(sz),ans(sz);
        int idx=0;
        for (vector<int> &i:mat) {
            int cnt=0;
            for (int j:i) {
                if (j==0) {
                    break;
                }
                cnt++;
            }
            ans.at(idx)=idx;
            vec.at(idx)=cnt;
            idx++;
        }
        sort(ans.begin(),ans.end(),[&vec](const int &A,const int &B){
            return (vec.at(A)<vec.at(B)) || 
            (vec.at(A)==vec.at(B) && A<B);
        });
        return vector<int>(ans.begin(),ans.begin()+k);
    }
};