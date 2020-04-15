//本来应该是从1开始bfs到0的最小距离，但这样又要遍历又要比较最小值，可以反过来从所有的0开始bfs搜索1
class Solution {
private:
    int dire[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if (row==0)
            return {};
        int column=matrix.at(0).size();
        vector<vector<int>> ans(row,vector<int>(column,0));
        vector<vector<bool>> visited(row,vector<bool>(column,false));
        queue<pair<int,int>> helper_queue;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (matrix.at(i).at(j)==0)
                {
                    helper_queue.push(make_pair(i,j));
                    visited.at(i).at(j)=true;
                }
        while (!helper_queue.empty())
        {
            auto [x,y]=helper_queue.front();
            helper_queue.pop();
            for (int i=0;i<4;++i)
            {
                int xx=x+dire[i][0];
                int yy=y+dire[i][1];
                if (xx>=0 && xx<row && yy>=0 && yy<column && !visited.at(xx).at(yy))
                {
                    visited.at(xx).at(yy)=true;
                    ans.at(xx).at(yy)=ans.at(x).at(y)+1;
                    helper_queue.push(make_pair(xx,yy));
                }
            }
        }
        return ans;
    }
};
