class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid.at(0).size();
        vector<int> ans(col,-1);
        for (int j=0;j<col;j++) {
            int cur=j;
            int i=0;
            for (i=0;i<row;i++) {
                if (grid.at(i).at(cur)==1) {
                    if (cur+1<col && grid.at(i).at(cur+1)==1) {
                        cur=cur+1;
                    } else {
                        break;
                    }
                } else {
                    if (cur-1>=0 && grid.at(i).at(cur-1)==-1) {
                        cur=cur-1;
                    } else {
                        break;
                    }
                }
            }
            if (i==row) {
                ans.at(j)=cur;
            }
        }
        return ans;
    }
};
