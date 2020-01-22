/*
* 对于一个元素target
* 比矩阵的左上角大，可能在下或右
* 比矩阵的右下角小，可能在上或左
* 比右上角大，必在下，比右上角小，必在左
* 比左下角小，必在上，比左下角大，必在右
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if (row==0)
            return false;
        int column=matrix.at(0).size();
        //左下角版本
        int x=row-1,y=0;
        while (x>=0 && y<column)
            if (matrix.at(x).at(y)==target)
                return true;
            else if (matrix.at(x).at(y)<target)
                ++y;
            else
                --x;
        return false;
    }
};
