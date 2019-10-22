//一次二分
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        if (row<1)
            return false;
        int column=matrix.at(0).size();
        if (column<1)
            return false;
        else if (target<matrix.at(0).at(0) || target>matrix.at(row-1).at(column-1))
            return false;
        int left=0,right=row*column-1,mid;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (matrix.at(mid/column).at(mid%column)==target)
                return true;
            else if (matrix.at(mid/column).at(mid%column)<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};
