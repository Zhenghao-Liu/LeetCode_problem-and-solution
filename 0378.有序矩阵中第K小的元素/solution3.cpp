class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left=matrix.at(0).at(0),right=matrix.back().back();
        while (left<right)
        {
            int mid=left+((right-left)>>1);
            int count=helper(matrix,mid);
            if (count<k)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
    int helper(vector<vector<int>> &matrix,int target)
    {
        int matrix_size=matrix.size(),i=matrix_size-1,j=0;
        int ans=0;
        while (i>=0 && j<matrix_size)
        {
            if (matrix.at(i).at(j)<=target)
            {
                ans+=i+1;
                ++j;
            }
            else
                --i;
        }
        return ans;
    }
};
