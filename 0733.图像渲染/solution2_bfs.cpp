typedef pair<int,int> pii;
class Solution {
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row=image.size();
        int column=image.at(0).size();
        vector<vector<bool>> use(row,vector<bool>(column,false));
        use.at(sr).at(sc)=true;
        queue<pii> helper;
        helper.push({sr,sc});
        int target=image.at(sr).at(sc);
        while (!helper.empty())
        {
            auto [x,y]=helper.front();
            helper.pop();
            image.at(x).at(y)=newColor;
            for (vector<int> &i:dir)
            {
                int xx=x+i.at(0);
                int yy=y+i.at(1);
                if (xx>=0 && xx<row && yy>=0 && yy<column && !use.at(xx).at(yy) && image.at(xx).at(yy)==target)
                {
                    use.at(xx).at(yy)=true;
                    helper.push({xx,yy});
                }
            }
        }
        return image;
    }
};
