//n^3做法，既然每次都要遍历长有多少，可以提前存好[i][j]左边有多少个连续的1，
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int row=mat.size();
        int column=mat.at(0).size();
        vector<vector<int>> left_one(row,vector<int>(column,0));
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (mat.at(i).at(j)==1)
                {
                    if (j-1>=0)
                        left_one.at(i).at(j)=left_one.at(i).at(j-1)+1;
                    else
                        left_one.at(i).at(j)=1;
                }
        int ans=0;
        for (int i=0;i<row;++i)
            for (int j=0;j<column;++j)
                if (mat.at(i).at(j)==1)
                {
                    int min_width=INT_MAX;
                    int ii=i;
                    while (ii>=0 && mat.at(ii).at(j)==1)
                    {
                        min_width=min(min_width,left_one.at(ii).at(j));
                        ans+=min_width;
                        --ii;
                    }
                }
        return ans;
    }
};
