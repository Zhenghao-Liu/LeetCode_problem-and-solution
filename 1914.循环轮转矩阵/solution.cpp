class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int row=grid.size(),col=grid.at(0).size();
        vector<vector<int>> ans(row,vector<int>(col));
        vector<int> vec;
        vec.reserve(1e3);
        for (int i=0;i*2<min(row,col);i++) {
            int m=row-i*2;
            int n=col-i*2;
            int all=(m+n)*2-4;
            vec.clear();
            for (int y=i;y<=i+n-1;y++) {
                vec.push_back(grid.at(i).at(y));   
            }
            for (int x=i+1;x<=i+m-1;x++) {
                vec.push_back(grid.at(x).at(i+n-1));
            }
            for (int y=i+n-2;y>=i;y--) {
                vec.push_back(grid.at(i+m-1).at(y));
            }
            for (int x=i+m-2;x>i;x--) {
                vec.push_back(grid.at(x).at(i));
            }
            int kk=k%all;
            for (int y=i;y<=i+n-1;y++) {
                ans.at(i).at(y)=vec.at(kk);
                kk=(kk+1)%all;
            }
            for (int x=i+1;x<=i+m-1;x++) {
                ans.at(x).at(i+n-1)=vec.at(kk);
                kk=(kk+1)%all;
            }
            for (int y=i+n-2;y>=i;y--) {
                ans.at(i+m-1).at(y)=vec.at(kk);
                kk=(kk+1)%all;
            }
            for (int x=i+m-2;x>i;x--) {
                ans.at(x).at(i)=vec.at(kk);
                kk=(kk+1)%all;
            }
        }
        return ans;
    }
};