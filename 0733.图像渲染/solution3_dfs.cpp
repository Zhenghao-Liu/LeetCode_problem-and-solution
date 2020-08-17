//因为变成了newcolor自然值也就不等于[sr][sc]的值了，所以可以省去use标记数组，不过一开始newcolor就等于[sr][sc]的话要特判
class Solution {
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.at(sr).at(sc)==newColor)
            return image;
        int row=image.size();
        int column=image.at(0).size();
        dfs(image,image.at(sr).at(sc),newColor,sr,sc,row,column);
        return image;
    }
    void dfs(vector<vector<int>> &image,int target,int newColor,int x,int y,int row,int column)
    {
        image.at(x).at(y)=newColor;
        for (vector<int> &i:dir)
        {
            int xx=x+i.at(0);
            int yy=y+i.at(1);
            if (xx>=0 && xx<row && yy>=0 && yy<column && image.at(xx).at(yy)==target)
                dfs(image,target,newColor,xx,yy,row,column);
        }
    }
};
