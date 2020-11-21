class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        ans.reserve(R*C);
        for (int i=0;i<R;++i)
            for (int j=0;j<C;++j)
                ans.push_back({i,j});
        sort(ans.begin(),ans.end(),[r0,c0](const vector<int> &A,const vector<int> &B){
            return abs(A.at(0)-r0)+abs(A.at(1)-c0) < abs(B.at(0)-r0)+abs(B.at(1)-c0);
        });
        return ans;
    }
};
