// Ax+By+C=0
// A = Y2 - Y1
// B = X1 - X2
// C = X2*Y1 - X1*Y2
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor) {
        int size=coor.size();
        int x1=coor.at(0).at(0);
        int y1=coor.at(0).at(1);
        int x2=coor.at(1).at(0);
        int y2=coor.at(1).at(1);
        int A=y2-y1;
        int B=x1-x2;
        int C=x2*y1-x1*y2;
        for (int i=2;i<size;i++) {
            int x=coor.at(i).at(0);
            int y=coor.at(i).at(1);
            if (A*x+B*y+C!=0) {
                return false;
            }
        }
        return true;
    }
};
