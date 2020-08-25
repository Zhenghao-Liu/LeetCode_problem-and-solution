//其实就是求入度为0的点
class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> use(n,false);
        for (vector<int> &i:edges)
            use.at(i.at(1))=true;
        vector<int> ans;
        for (int i=0;i<n;++i)
            if (!use.at(i))
                ans.push_back(i);
        return ans;
    }
};
