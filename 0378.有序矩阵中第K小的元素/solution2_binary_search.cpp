class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int left=matrix.at(0).at(0),right=matrix.back().back();
        while (left<right)
        {
            int count=0;
            int mid=left+((right-left)>>1);
            for (vector<int> &i:matrix)
                count+=upper_bound(i.begin(),i.end(),mid)-i.begin();
            if (count<k)
                left=mid+1;
            else
                right=mid;
        }
        return left;
    }
};
