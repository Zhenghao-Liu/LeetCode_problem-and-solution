class Solution {
    int row,col;
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        row=8,col=8;
        int dir[][2]={{-1,0},{0,1},{1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        board.at(rMove).at(cMove)=color;
        for (int i=0;i<8;i++) {
            int x=dir[i][0],y=dir[i][1];
            if (check(board,rMove,cMove,x,y)) {
                return true;
            }
        }
        return false;
    }
    bool check(vector<vector<char>>& board,int x,int y,int id,int jd) {
        int i=x+id,j=y+jd;
        int cnt=0;
        for (;i<row && i>=0 && j>=0 && j<col;i=i+id,j=j+jd) {
            char cur=board.at(i).at(j);
            if (cur=='.' || cur==board.at(x).at(y)) {
                break;
            }
            cnt++;
        }
        if (!(i<row && i>=0 && j>=0 && j<col) || board.at(i).at(j)=='.') {
            return false;
        }
        return cnt>=1; 
    }
};