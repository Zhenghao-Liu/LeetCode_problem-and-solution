const int MAXN=543210+1;
int vis[MAXN];
const int tar=123450;
const int INF=0x3f3f3f3f;
const int row=2,col=3;
int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
class Solution {
    vector<int> vec;
    vector<vector<int>> number;
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int num=0;
        for (vector<int> &i:board) {
            for (int j:i) {
                num=num*10+j;
            }
        }
        if (tar==num) {
            return 0;
        }
        vec=vector<int>(3);
        number=vector<vector<int>>(row,vector<int>(col));
        memset(vis,0x3f,sizeof(vis));
        vis[num]=0;
        queue<int> que;
        que.push(num);
        while (!que.empty()) {
            int cur=que.front();
            que.pop();
            helper(cur);
            for (int nxt:vec) {
                if (nxt==0 || vis[nxt]!=INF) {
                    continue;
                }
                vis[nxt]=vis[cur]+1;
                que.push(nxt);
                if (nxt==tar) {
                    return vis[nxt];
                }
            }
        }
        return -1;
    }
    void helper(int cur) {
        in(cur);
        fill(vec.begin(),vec.end(),0);
        int x=0,y=0;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (number.at(i).at(j)==0) {
                    x=i;
                    y=j;
                }
            }
        }
        int idx=0;
        for (int k=0;k<4;k++) {
            int xx=x+dir[k][0];
            int yy=y+dir[k][1];
            if (!(xx>=0 && xx<row && yy>=0 && yy<col)) {
                continue;
            }
            swap(number.at(x).at(y),number.at(xx).at(yy));
            vec.at(idx)=out();
            idx++;
            swap(number.at(x).at(y),number.at(xx).at(yy));
        }
    }
    void in(int cur) {
        for (int i=row-1;i>=0;i--) {
            for (int j=col-1;j>=0;j--) {
                number.at(i).at(j)=cur%10;
                cur/=10;
            }
        }
    }
    int out() {
        int ans=0;
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                ans=ans*10+number.at(i).at(j);
            }
        }
        return ans;
    }
};