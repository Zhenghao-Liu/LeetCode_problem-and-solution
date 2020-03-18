//采用cache缓存路径
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row=matrix.size();
        if (row==0)
            return 0;
        int column=matrix.at(0).size();
        vector<vector<int>> cache(row,vector<int>(column,0));
        int ans=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                ans=max(ans,dfs(matrix,cache,row,column,i,j));
        return ans;
    }
    int dfs(vector<vector<int>> & matrix,vector<vector<int>> & cache,const int &row,const int &column,int x,int y)
    {
        if (cache.at(x).at(y)!=0)
            return cache.at(x).at(y);
        //左
        if (y>0 && matrix.at(x).at(y)>matrix.at(x).at(y-1))
            cache.at(x).at(y)=max(cache.at(x).at(y),dfs(matrix,cache,row,column,x,y-1));
        //上
        if (x>0 && matrix.at(x).at(y)>matrix.at(x-1).at(y))
            cache.at(x).at(y)=max(cache.at(x).at(y),dfs(matrix,cache,row,column,x-1,y));
        //右
        if (y+1<column && matrix.at(x).at(y)>matrix.at(x).at(y+1))
            cache.at(x).at(y)=max(cache.at(x).at(y),dfs(matrix,cache,row,column,x,y+1));
        //下
        if (x+1<row && matrix.at(x).at(y)>matrix.at(x+1).at(y))
            cache.at(x).at(y)=max(cache.at(x).at(y),dfs(matrix,cache,row,column,x+1,y));
        ++cache.at(x).at(y);
        return cache.at(x).at(y);
    }
};
