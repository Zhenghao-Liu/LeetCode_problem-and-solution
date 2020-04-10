class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row=matrix.size();
        if (row==0)
            return 0;
        int column=matrix.at(0).size();
        int ans=INT_MIN;
        for (int left=0;left<column;++left)
        {
            vector<int> row_sum(row,0);
            for (int right=left;right<column;++right)
            {
                for (int i=0;i<row;++i)
                    row_sum.at(i)+=matrix.at(i).at(right);
                set<int> helper_set;
                helper_set.insert(0);
                int prefix_row_sum=0;
                for (int i=0;i<row;++i)
                {
                    prefix_row_sum+=row_sum.at(i);
                    auto p=helper_set.lower_bound(prefix_row_sum-k);
                    helper_set.insert(prefix_row_sum);
                    if (p==helper_set.end())
                        continue;
                    else
                    {
                        int temp=prefix_row_sum-(*p);
                        if (temp>ans)
                            ans=temp;
                    }
                }
                if (ans==k)
                    return k;
            }
        }        
        return ans;
    }
};
