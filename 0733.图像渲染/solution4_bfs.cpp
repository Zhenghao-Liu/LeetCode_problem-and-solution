//因为变成了newcolor自然值也就不等于[sr][sc]的值了，不过一开始newcolor就等于[sr][sc]的话要特判
typedef pair<int,int> pii;
class Solution {
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int target=image.at(sr).at(sc);
        if (newColor==target)
            return image;
        image.at(sr).at(sc)=newColor;
        int row=image.size();
        int column=image.at(0).size();
        queue<pii> helper;
        helper.push({sr,sc});
        while (!helper.empty())
        {
            auto [x,y]=helper.front();
            helper.pop();
            for (vector<int> &i:dir)
            {
                int xx=x+i.at(0);
                int yy=y+i.at(1);
                if (xx>=0 && xx<row && yy>=0 && yy<column && image.at(xx).at(yy)==target)
                {
                    image.at(xx).at(yy)=newColor;
                    helper.push({xx,yy});
                }
            }
        }
        return image;
    }
};
