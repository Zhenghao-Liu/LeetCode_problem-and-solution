//i,j->j,row-i-1
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row=box.size(),col=box.at(0).size();
        vector<vector<char>> b(row,vector<char>(col));
        for (int i=0;i<row;i++) {
            box.at(i).push_back('*');
        }
        for (int i=0;i<row;i++) {
            int cnt=0;
            for (int j=0;j<=col;j++) {
                if (box.at(i).at(j)=='#') {
                    cnt++;
                } else if (box.at(i).at(j)=='*') {
                    for (int k=0;k<cnt;k++) {
                        b.at(i).at(j-k-1)='#';
                    }
                    cnt=0;
                }
            }
        }
        vector<vector<char>> ans(col,vector<char>(row,'.'));
        for (int i=0;i<row;i++) {
            for (int j=0;j<col;j++) {
                if (box.at(i).at(j)=='*') {
                    ans.at(j).at(row-1-i)='*';
                } else if (b.at(i).at(j)=='#') {
                    ans.at(j).at(row-1-i)='#';
                }
            }
        }
        return ans;
    }
};