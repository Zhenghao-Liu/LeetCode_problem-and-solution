class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int sz=arr.size();
        vector<int> vec(sz+1);
        for (int i=0;i<sz;i++) {
            vec.at(i+1)=vec.at(i)^arr.at(i);
        }
        int qSz=queries.size();
        vector<int> ans(qSz);
        for (int i=0;i<qSz;i++) {
            int a=queries.at(i).at(0),b=queries.at(i).at(1);
            ans.at(i)=vec.at(b+1)^vec.at(a);
        }
        return ans;
    }
};