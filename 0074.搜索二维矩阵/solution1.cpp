/*
* 方法一:两次折半
* 对第一列进行一次二分，再对其对应的行进行一次二分
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size(),left=0,right=row-1,mid;
        if (row==0)
            return false;
        int column=matrix.at(0).size();
        if (column==0)
            return false;
        else if (target<matrix.at(0).at(0) || target>matrix.at(row-1).at(column-1))
            return false;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (matrix.at(mid).at(0)==target)
                return true;
            else if (matrix.at(mid).at(0)<target)
                left=mid+1;
            else
                right=mid-1;
        }
        row=left-1;
        left=0;
        right=column-1;
        while (left<=right)
        {
            mid=(left+right)/2;
            if (matrix.at(row).at(mid)==target)
                return true;
            else if (matrix.at(row).at(mid)<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};
