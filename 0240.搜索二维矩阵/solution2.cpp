class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if (row==0)
            return false;
        int column=matrix.at(0).size();
        //右上角版本
        int x=0,y=column-1;
        while (x<row && y>=0)
            if (matrix.at(x).at(y)==target)
                return true;
            else if (matrix.at(x).at(y)<target)
                ++x;
            else
                --y;
        return false;
    }
};
