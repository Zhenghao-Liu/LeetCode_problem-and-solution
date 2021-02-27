int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& w) {
        int row=w.size();
        int col=w.at(0).size();
        vector<vector<int>> ans(row,vector<int>(col,INT_MIN));
        queue<int> que;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (w.at(i).at(j)==1) {
                    ans.at(i).at(j)=0;
                    que.push(i*col+j);
                }
            }
        }
        while (!que.empty()) {
            int cur=que.front();
            que.pop();
            int x=cur/col;
            int y=cur%col;
            int val=ans.at(x).at(y)+1;
            for (int i=0;i<4;i++) {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if (!(xx>=0 && xx<row && yy>=0 && yy<col)) {
                    continue;
                }
                if (ans.at(xx).at(yy)!=INT_MIN) {
                    continue;
                }
                ans.at(xx).at(yy)=val;
                que.push(xx*col+yy);
            }
        }
        return ans;
    }
};
