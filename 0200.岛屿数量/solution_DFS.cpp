//和130题有相似的地方
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        if (row<1)
            return 0;
        int column=grid.at(0).size(),answer=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (grid.at(i).at(j)=='1')
                {
                    ++answer;
                    find_islands(grid,row,column,i,j);
                }
        return answer;
    }
    void find_islands(vector<vector<char>>& grid,const int& row,const int& column,int i,int j)
    {
        if (i<0 || i>=row || j<0 || j>=column || grid.at(i).at(j)!='1')
            return;
        grid.at(i).at(j)='2';
        find_islands(grid,row,column,i-1,j);//上
        find_islands(grid,row,column,i+1,j);//下
        find_islands(grid,row,column,i,j-1);//左
        find_islands(grid,row,column,i,j+1);//右
    }
};
